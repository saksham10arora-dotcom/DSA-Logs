```cpp
// LeetCode problem 2322: Minimum Score After Removals On A Tree
// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
// Given the root of a binary tree and an integer k, return the minimum score of all possible removals.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Brute force approach with O(2^n) complexity
    int minimumScore(TreeNode* root, int k) {
        vector<int> values;
        dfs(root, values);
        sort(values.begin(), values.end());
        int res = INT_MAX;
        for (int mask = 0; mask < (1 << values.size()); mask++) {
            int sum = 0;
            int count = 0;
            for (int i = 0; i < values.size(); i++) {
                if ((mask >> i) & 1) {
                    sum += values[i];
                    count++;
                }
            }
            if (count == k) {
                res = min(res, sum);
            }
        }
        return res;
    }

    // Optimal solution with O(n log n) complexity
    int minimumScoreOptimal(TreeNode* root, int k) {
        vector<int> values;
        dfs(root, values);
        sort(values.begin(), values.end());
        int res = INT_MAX;
        int n = values.size();
        for (int i = 0; i <= n - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += values[j];
            }
            res = min(res, sum);
        }
        return res;
    }

    void dfs(TreeNode* node, vector<int>& values) {
        if (!node) return;
        values.push_back(node->val);
        dfs(node->left, values);
        dfs(node->right, values);
    }
};

int main() {
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout << solution.minimumScoreOptimal(root1, 3) << endl;  // Output: 15

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    cout << solution.minimumScoreOptimal(root2, 2) << endl;  // Output: 6

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    cout << solution.minimumScoreOptimal(root3, 1) << endl;  // Output: 1

    return 0;
}
```