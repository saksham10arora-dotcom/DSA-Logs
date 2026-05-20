```cpp
// LeetCode problem 114: Flatten Binary Tree To Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.

// Brute force approach: O(n) time complexity, O(n) space complexity
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if (!root) return;
//         vector<int> nodes;
//         dfs(root, nodes);
//         for (int i = 0; i < nodes.size(); i++) {
//             TreeNode* node = new TreeNode(nodes[i]);
//             if (i > 0) {
//                 prev->right = node;
//                 prev->left = nullptr;
//             }
//             prev = node;
//         }
//     }
// private:
//     void dfs(TreeNode* node, vector<int>& nodes) {
//         if (!node) return;
//         nodes.push_back(node->val);
//         dfs(node->left, nodes);
//         dfs(node->right, nodes);
//     }
//     TreeNode* prev = nullptr;
// };

// Optimal solution: O(n) time complexity, O(n) space complexity
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root, nullptr);
    }
private:
    TreeNode* flatten(TreeNode* node, TreeNode* tail) {
        if (!node) return tail;
        TreeNode* right = flatten(node->right, tail);
        TreeNode* left = flatten(node->left, right);
        node->right = left;
        node->left = nullptr;
        return node;
    }
};

int main() {
    // Test case 1:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);
    Solution().flatten(root1);
    // Expected output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

    // Test case 2:
    TreeNode* root2 = new TreeNode(0);
    Solution().flatten(root2);
    // Expected output: 0

    // Test case 3:
    TreeNode* root3 = nullptr;
    Solution().flatten(root3);
    // Expected output: 

    return 0;
}
```