```cpp
// LeetCode problem 1302: Deepest Leaves Sum, https://leetcode.com/problems/deepest-leaves-sum/
// Given the root of a binary tree, return the sum of the values of its deepest leaves.

// Brute force approach: O(n) time complexity, O(n) space complexity
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        int deepestLevel = -1;
        int sum = 0;
        while (!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level > deepestLevel) {
                deepestLevel = level;
                sum = node->val;
            } else if (level == deepestLevel) {
                sum += node->val;
            }
            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }
        return sum;
    }
};

// Optimal solution: O(n) time complexity, O(n) space complexity
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        int deepestLevel = -1;
        int sum = 0;
        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            for (int i = 0; i < size; i++) {
                auto node = q.front().first;
                int level = q.front().second;
                q.pop();
                if (level > deepestLevel) {
                    deepestLevel = level;
                    sum = node->val;
                } else if (level == deepestLevel) {
                    sum += node->val;
                }
                levelSum += node->val;
                if (node->left) q.push({node->left, level + 1});
                if (node->right) q.push({node->right, level + 1});
            }
            if (deepestLevel == q.front().second - 1) {
                sum = levelSum;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    TreeNode* root1 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    std::cout << solution.deepestLeavesSum(root1) << std::endl;  // Output: 9

    TreeNode* root2 = new TreeNode(6, new TreeNode(7, new TreeNode(2, new TreeNode(7), new TreeNode(1)), new TreeNode(7)), new TreeNode(8, new TreeNode(1), new TreeNode(0)));
    std::cout << solution.deepestLeavesSum(root2) << std::endl;  // Output: 8

    TreeNode* root3 = new TreeNode(1);
    std::cout << solution.deepestLeavesSum(root3) << std::endl;  // Output: 1

    return 0;
}
```