```cpp
// Create Binary Tree From Descriptions, https://leetcode.com/problems/create-binary-tree-from-descriptions/
// Given a list of descriptions of the nodes in a binary tree, create the binary tree.

// Brute force approach with O(n^2) complexity
// class Solution {
// public:
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         unordered_map<int, TreeNode*> nodes;
//         for (auto& desc : descriptions) {
//             int parent = desc[0], child = desc[1], isLeft = desc[2];
//             if (nodes.find(parent) == nodes.end()) {
//                 nodes[parent] = new TreeNode(parent);
//             }
//             if (nodes.find(child) == nodes.end()) {
//                 nodes[child] = new TreeNode(child);
//             }
//             if (isLeft) {
//                 nodes[parent]->left = nodes[child];
//             } else {
//                 nodes[parent]->right = nodes[child];
//             }
//         }
//         for (auto& desc : descriptions) {
//             int parent = desc[0], child = desc[1], isLeft = desc[2];
//             if (nodes.find(parent) == nodes.end()) {
//                 nodes[parent] = new TreeNode(parent);
//             }
//             if (nodes.find(child) == nodes.end()) {
//                 nodes[child] = new TreeNode(child);
//             }
//             if (isLeft) {
//                 nodes[parent]->left = nodes[child];
//             } else {
//                 nodes[parent]->right = nodes[child];
//             }
//         }
//         for (auto& node : nodes) {
//             if (node.second->left == nullptr && node.second->right == nullptr) {
//                 continue;
//             }
//             return node.second;
//         }
//         return nullptr;
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        int root;
        for (auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            root = parent;
        }
        for (auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
        }
        for (auto& node : nodes) {
            if (nodes.find(node.first) != nodes.end() && node.second->left == nullptr && node.second->right == nullptr) {
                continue;
            }
            return nodes[root];
        }
        return nullptr;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> descriptions1 = {{20,15,1},{20,18,1},{11,15,0},{11,18,0},{15,3,0},{18,5,0}};
    vector<vector<int>> descriptions2 = {{1,2,1},{2,3,0},{3,4,1}};
    vector<vector<int>> descriptions3 = {{1,2,1},{2,3,0},{3,4,1},{4,5,1},{4,6,0}};
    TreeNode* root1 = solution.createBinaryTree(descriptions1);
    TreeNode* root2 = solution.createBinaryTree(descriptions2);
    TreeNode* root3 = solution.createBinaryTree(descriptions3);
    return 0;
}
```