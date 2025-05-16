```cpp
// LeetCode problem 1868: Count Good Nodes I I I, https://leetcode.com/problems/count-good-nodes-in-binary-tree-iii/
// Given the root of a binary tree, count the number of good nodes.

#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Brute force approach with O(n^2) complexity
    int goodNodesBrute(TreeNode* root) {
        int count = 0;
        std::vector<int> path;
        dfsBrute(root, path, count);
        return count;
    }

    void dfsBrute(TreeNode* node, std::vector<int>& path, int& count) {
        if (!node) return;
        bool isGood = true;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] > node->val) {
                isGood = false;
                break;
            }
        }
        if (isGood) count++;
        path.push_back(node->val);
        dfsBrute(node->left, path, count);
        dfsBrute(node->right, path, count);
        path.pop_back();
    }

    // Optimal solution with O(n) complexity
    int goodNodesOptimal(TreeNode* root) {
        int count = 0;
        dfsOptimal(root, INT_MIN, count);
        return count;
    }

    void dfsOptimal(TreeNode* node, int maxVal, int& count) {
        if (!node) return;
        if (node->val >= maxVal) {
            count++;
            maxVal = node->val;
        }
        dfsOptimal(node->left, maxVal, count);
        dfsOptimal(node->right, maxVal, count);
    }
};

int main() {
    Solution solution;

    // Test case 1:
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    std::cout << "Test case 1: " << solution.goodNodesOptimal(root1) << std::endl;

    // Test case 2:
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(1);
    std::cout << "Test case 2: " << solution.goodNodesOptimal(root2) << std::endl;

    // Test case 3:
    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(8);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->right = new TreeNode(9);
    std::cout << "Test case 3: " << solution.goodNodesOptimal(root3) << std::endl;

    return 0;
}
```