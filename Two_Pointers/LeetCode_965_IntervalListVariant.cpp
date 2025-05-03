```cpp
// LeetCode problem 965: Interval List Variant, https://leetcode.com/problems/univalued-binary-tree/
// A univalued binary tree is a binary tree where every node has the same value.
// Given the root of a binary tree, return true if the tree is univalued, or false otherwise.

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Brute force approach with O(N) complexity, where N is the number of nodes in the tree
    bool isUnivalTreeBrute(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->left->val!= root->val) return false;
        if (root->right && root->right->val!= root->val) return false;
        return isUnivalTreeBrute(root->left) && isUnivalTreeBrute(root->right);
    }

    // Optimal solution with O(N) complexity, where N is the number of nodes in the tree
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);
    }

    bool isUnivalTree(TreeNode* root, int val) {
        if (!root) return true;
        if (root->val!= val) return false;
        return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};

int main() {
    Solution solution;

    // Test case 1:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(1);
    std::cout << std::boolalpha << solution.isUnivalTree(root1) << std::endl;  // Expected output: true

    // Test case 2:
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(2);
    root2->right->right = new TreeNode(2);
    std::cout << std::boolalpha << solution.isUnivalTree(root2) << std::endl;  // Expected output: true

    // Test case 3:
    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(2);
    root3->left->left = new TreeNode(2);
    root3->left->right = new TreeNode(3);
    root3->right->right = new TreeNode(2);
    std::cout << std::boolalpha << solution.isUnivalTree(root3) << std::endl;  // Expected output: false

    return 0;
}
```