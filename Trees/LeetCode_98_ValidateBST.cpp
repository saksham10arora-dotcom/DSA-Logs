/**
 * Problem: Validate Binary Search Tree (LeetCode 98)
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
 */

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimal Solution ---
// Time Complexity: O(N)
// Space Complexity: O(H)
bool isValid(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return isValid(node->left, minVal, node->val) && 
           isValid(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    cout << (isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;
    return 0;
}




























