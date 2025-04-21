```cpp
// LeetCode problem 124: Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Given a non-empty binary tree, return the maximum path sum.

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // Brute force approach: O(2^n) - calculate all possible paths and return the maximum
        // However, this approach is inefficient and will exceed the time limit for large inputs

        // Optimal solution: O(n) - use a recursive approach to calculate the maximum path sum
        max_sum = INT_MIN;
        maxGain(root);
        return max_sum;
    }

private:
    int max_sum;

    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int left_gain = max(maxGain(node->left), 0);
        int right_gain = max(maxGain(node->right), 0);
        int price_newpath = node->val + left_gain + right_gain;
        max_sum = max(max_sum, price_newpath);
        return node->val + max(left_gain, right_gain);
    }
};

int main() {
    Solution solution;

    // Test case 1:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    printf("%d\n", solution.maxPathSum(root1));  // Output: 6

    // Test case 2:
    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    printf("%d\n", solution.maxPathSum(root2));  // Output: 42

    // Test case 3:
    TreeNode* root3 = new TreeNode(-3);
    printf("%d\n", solution.maxPathSum(root3));  // Output: -3

    return 0;
}
```