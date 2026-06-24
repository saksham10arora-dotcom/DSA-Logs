```cpp
// LeetCode problem 572: Subtree Of Another Tree, https://leetcode.com/problems/subtree-of-another-tree/
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values as subRoot and false otherwise.

// Brute force approach with O(n*m) complexity, where n and m are the number of nodes in the two trees
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Optimal solution with O(n*m) complexity, where n and m are the number of nodes in the two trees
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Test case 1:
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);

    TreeNode* subRoot1 = new TreeNode(4);
    subRoot1->left = new TreeNode(1);
    subRoot1->right = new TreeNode(2);

    Solution solution;
    bool result1 = solution.isSubtree(root1, subRoot1);
    // Output: true

    // Test case 2:
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);

    TreeNode* subRoot2 = new TreeNode(4);
    subRoot2->left = new TreeNode(1);
    subRoot2->right = new TreeNode(3);

    bool result2 = solution.isSubtree(root2, subRoot2);
    // Output: false

    // Test case 3:
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(1);

    TreeNode* subRoot3 = new TreeNode(1);

    bool result3 = solution.isSubtree(root3, subRoot3);
    // Output: true

    return 0;
}
```