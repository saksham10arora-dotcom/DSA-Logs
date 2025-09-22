```cpp
// Maximum Binary Tree II, https://leetcode.com/problems/maximum-binary-tree-ii/
// Given the root of a binary tree and an integer value, insert a new node with the given value into the tree.
// The new node should be inserted in the first empty left child or right child of a leaf node with the same value.

// Brute force approach: O(n) time complexity, O(n) space complexity
// class Solution {
// public:
//     TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
//         if (!root) return new TreeNode(val);
//         if (val > root->val) {
//             TreeNode* newNode = new TreeNode(val);
//             newNode->left = root;
//             return newNode;
//         }
//         root->right = insertIntoMaxTree(root->right, val);
//         return root;
//     }
// };

// Optimal solution: O(n) time complexity, O(n) space complexity
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val > root->val) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

int main() {
    Solution solution;
    // Test case 1:
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(2);
    TreeNode* result1 = solution.insertIntoMaxTree(root1, 5);
    // Test case 2:
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(0);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(2);
    TreeNode* result2 = solution.insertIntoMaxTree(root2, 4);
    // Test case 3:
    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(0);
    root3->left->right = new TreeNode(3);
    root3->right->right = new TreeNode(2);
    TreeNode* result3 = solution.insertIntoMaxTree(root3, 6);
    return 0;
}
```