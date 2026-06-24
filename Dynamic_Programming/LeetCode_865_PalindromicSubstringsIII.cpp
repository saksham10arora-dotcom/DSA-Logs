```cpp
// LeetCode problem 865: Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Given the root of a binary tree, return the root of the smallest subtree such that it contains all the deepest nodes.

// Brute force approach with O(N^2) complexity
// class Solution {
// public:
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         // ...
//     }
// };

// Optimal solution with O(N) complexity
class Solution {
public:
    int maxDepth = 0;
    TreeNode* ans;
    int depth(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
    bool dfs(TreeNode* node, int d) {
        if (!node) return false;
        bool left = dfs(node->left, d + 1);
        bool right = dfs(node->right, d + 1);
        if (left && right) return true;
        if (left || right) return depth(node->left) == depth(node->right) && depth(node->left) + d == maxDepth;
        return d == maxDepth;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = depth(root);
        dfs(root, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    // Test case 1:
    //      3
    //     / \
    //    5   1
    //   / \   \
    //  6   2   0
    //     / \
    //    7   4
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->right = new TreeNode(0);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    TreeNode* result1 = solution.subtreeWithAllDeepest(root1);
    // Test case 2:
    //      1
    TreeNode* root2 = new TreeNode(1);
    TreeNode* result2 = solution.subtreeWithAllDeepest(root2);
    // Test case 3:
    //      0
    TreeNode* root3 = new TreeNode(0);
    TreeNode* result3 = solution.subtreeWithAllDeepest(root3);
    return 0;
}
```