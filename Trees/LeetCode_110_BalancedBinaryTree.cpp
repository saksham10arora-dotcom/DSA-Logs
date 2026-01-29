/**
 * Problem: Balanced Binary Tree (LeetCode 110)
 * Link: https://leetcode.com/problems/balanced-binary-tree/
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimal Solution ---
// Time Complexity: O(N)
// Space Complexity: O(H)
int checkHeight(TreeNode* node) {
    if (!node) return 0;
    int lh = checkHeight(node->left);
    if (lh == -1) return -1;
    int rh = checkHeight(node->right);
    if (rh == -1) return -1;
    
    if (abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << (isBalanced(root) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
























