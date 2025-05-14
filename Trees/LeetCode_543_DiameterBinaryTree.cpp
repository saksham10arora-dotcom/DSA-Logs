/**
 * Problem: Diameter of Binary Tree (LeetCode 543)
 * Link: https://leetcode.com/problems/diameter-of-binary-tree/
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
// Space Complexity: O(H) - where H is the height of the tree
int height(TreeNode* node, int& diameter) {
    if (!node) return 0;
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int getDiameter(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Diameter: " << getDiameter(root) << endl;
    return 0;
}

















