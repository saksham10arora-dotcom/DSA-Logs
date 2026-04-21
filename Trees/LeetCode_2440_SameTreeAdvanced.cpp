```cpp
// LeetCode problem 2440: Same Tree Advanced
// https://leetcode.com/problems/same-tree-advanced/
// Given the roots of two binary trees, return whether the two trees are the same or not.

// Brute force approach: compare each node of the two trees recursively, O(n) where n is the total number of nodes
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Optimal solution: same as brute force, as we need to compare each node, O(n) where n is the total number of nodes
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Test case 1:
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    Solution solution;
    std::cout << std::boolalpha << solution.isSameTree(p, q) << std::endl;  // Expected output: true

    // Test case 2:
    p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(4);
    std::cout << std::boolalpha << solution.isSameTree(p, q) << std::endl;  // Expected output: false

    // Test case 3:
    p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    q = new TreeNode(1);
    q->left = new TreeNode(2);
    std::cout << std::boolalpha << solution.isSameTree(p, q) << std::endl;  // Expected output: false

    return 0;
}
```