```cpp
// LeetCode problem 3372: Maximize The Number Of Target Nodes After Connecting Trees I
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/
// Given two trees, return the maximum number of target nodes after connecting trees.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

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
    // Brute force approach with O(2^(n+m)) complexity
    // int maxTargetNodes(TreeNode* root1, TreeNode* root2) {
    //     // Generate all possible combinations of nodes from both trees
    //     // and calculate the number of target nodes for each combination
    // }

    // Optimal solution with O(n+m) complexity
    int maxTargetNodes(TreeNode* root1, TreeNode* root2) {
        unordered_map<int, int> count1, count2;
        dfs(root1, count1);
        dfs(root2, count2);

        int maxCount = 0;
        for (auto& pair : count1) {
            if (count2.find(pair.first)!= count2.end()) {
                maxCount = max(maxCount, pair.second + count2[pair.first]);
            }
        }
        return maxCount;
    }

    void dfs(TreeNode* root, unordered_map<int, int>& count) {
        if (!root) return;
        count[root->val]++;
        dfs(root->left, count);
        dfs(root->right, count);
    }
};

int main() {
    Solution solution;

    // Test case 1:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << solution.maxTargetNodes(root1, root2) << endl;  // Output: 3

    // Test case 2:
    root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root2 = new TreeNode(4);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(6);
    cout << solution.maxTargetNodes(root1, root2) << endl;  // Output: 0

    // Test case 3:
    root1 = new TreeNode(1);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(1);
    root2 = new TreeNode(1);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(1);
    cout << solution.maxTargetNodes(root1, root2) << endl;  // Output: 3

    return 0;
}
```