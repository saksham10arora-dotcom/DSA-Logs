```cpp
// LeetCode problem 98: Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Brute force approach: O(n^2) complexity, where n is the number of nodes in the tree
    bool isValidBSTBruteForce(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->val <= getMax(root->left)) return false;
        if (root->right && root->val >= getMin(root->right)) return false;
        return isValidBSTBruteForce(root->left) && isValidBSTBruteForce(root->right);
    }

    int getMax(TreeNode* node) {
        int maxVal = node->val;
        while (node->right) {
            node = node->right;
            maxVal = node->val;
        }
        return maxVal;
    }

    int getMin(TreeNode* node) {
        int minVal = node->val;
        while (node->left) {
            node = node->left;
            minVal = node->val;
        }
        return minVal;
    }

    // Optimal solution: O(n) complexity, where n is the number of nodes in the tree
    bool isValidBSTOptimal(TreeNode* root) {
        return isValidBSTOptimal(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTOptimal(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return isValidBSTOptimal(node->left, minVal, node->val) && isValidBSTOptimal(node->right, node->val, maxVal);
    }
};

int main() {
    Solution solution;

    // Test case 1:
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    std::cout << std::boolalpha << solution.isValidBSTOptimal(root1) << std::endl;  // Expected output: true

    // Test case 2:
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    std::cout << std::boolalpha << solution.isValidBSTOptimal(root2) << std::endl;  // Expected output: false

    // Test case 3:
    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->left->left = new TreeNode(3);
    root3->left->right = new TreeNode(7);
    root3->right->right = new TreeNode(18);
    std::cout << std::boolalpha << solution.isValidBSTOptimal(root3) << std::endl;  // Expected output: true

    return 0;
}
```