```cpp
// Smallest Missing Genetic Value In Each Subtree, https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/
// Brief description: Given the root of a binary tree where each node has a unique value and a list of distinct integers start, 
// find the smallest missing genetic value in each subtree rooted at a node in the list.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> smallestMissingValueSubtree(TreeNode* root, vector<int>& nodes) {
        unordered_set<int> s;
        for (int node : nodes) s.insert(node);
        vector<int> res(nodes.size());
        int index = 0;
        for (int node : nodes) {
            res[index++] = dfs(root, node, s);
        }
        return res;
    }

    int dfs(TreeNode* root, int node, unordered_set<int>& s) {
        if (!root) return 1;
        if (root->val == node) {
            int res = 1;
            unordered_set<int> t;
            dfs2(root, t);
            while (t.count(res)) res++;
            return res;
        }
        return dfs(root->left, node, s) | dfs(root->right, node, s);
    }

    void dfs2(TreeNode* root, unordered_set<int>& s) {
        if (!root) return;
        s.insert(root->val);
        dfs2(root->left, s);
        dfs2(root->right, s);
    }
};

// Brute force approach with O(n^2) complexity
// Optimal solution with O(n) complexity

int main() {
    Solution solution;
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(11);
    root1->right = new TreeNode(54);
    root1->left->left = new TreeNode(21);
    root1->left->right = new TreeNode(14);
    root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(25);
    root1->left->left->right = new TreeNode(24);
    vector<int> nodes1 = {3, 1, 27};
    vector<int> res1 = solution.smallestMissingValueSubtree(root1, nodes1);
    for (int i : res1) cout << i << " ";
    cout << endl;

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(4);
    vector<int> nodes2 = {2};
    vector<int> res2 = solution.smallestMissingValueSubtree(root2, nodes2);
    for (int i : res2) cout << i << " ";
    cout << endl;

    TreeNode* root3 = new TreeNode(1);
    vector<int> nodes3 = {1};
    vector<int> res3 = solution.smallestMissingValueSubtree(root3, nodes3);
    for (int i : res3) cout << i << " ";
    cout << endl;

    return 0;
}
```