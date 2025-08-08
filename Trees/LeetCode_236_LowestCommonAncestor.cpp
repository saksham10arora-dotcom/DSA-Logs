/**
 * Problem: Lowest Common Ancestor of a Binary Tree (LeetCode 236)
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimal Solution (Recursive) ---
// Time Complexity: O(N)
// Space Complexity: O(H)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (!left) return right;
    if (!right) return left;
    return root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    
    TreeNode* lca = lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << "LCA: " << lca->val << endl; // Should be 5
    return 0;
}
























