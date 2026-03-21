```cpp
// LeetCode problem 173: Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.

#include <iostream>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* topmostNode = stack.top();
        stack.pop();
        if (topmostNode->right) {
            pushLeft(topmostNode->right);
        }
        return topmostNode->val;
    }

    bool hasNext() {
        return!stack.empty();
    }

    void pushLeft(TreeNode* node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }
};

int main() {
    // Test case 1
    TreeNode* root1 = new TreeNode(7);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(15);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(20);
    BSTIterator iterator1(root1);
    std::cout << iterator1.next() << std::endl; // Output: 3
    std::cout << iterator1.next() << std::endl; // Output: 7
    std::cout << iterator1.next() << std::endl; // Output: 9
    std::cout << iterator1.next() << std::endl; // Output: 15
    std::cout << iterator1.next() << std::endl; // Output: 20

    // Test case 2
    TreeNode* root2 = new TreeNode(1);
    BSTIterator iterator2(root2);
    std::cout << iterator2.next() << std::endl; // Output: 1

    // Test case 3
    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(7);
    root3->left->left = new TreeNode(2);
    root3->left->right = new TreeNode(4);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(8);
    BSTIterator iterator3(root3);
    std::cout << iterator3.next() << std::endl; // Output: 2
    std::cout << iterator3.next() << std::endl; // Output: 3
    std::cout << iterator3.next() << std::endl; // Output: 4
    std::cout << iterator3.next() << std::endl; // Output: 5
    std::cout << iterator3.next() << std::endl; // Output: 6
    std::cout << iterator3.next() << std::endl; // Output: 7
    std::cout << iterator3.next() << std::endl; // Output: 8

    return 0;
}
```