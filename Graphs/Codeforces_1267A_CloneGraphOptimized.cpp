```cpp
// Codeforces_1267A_CloneGraphOptimized
// https://codeforces.com/contest/1267/problem/A
// Clone a graph in an optimized manner.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
// This approach involves creating a new graph and copying all nodes and edges from the original graph.
// However, this approach is inefficient and can be optimized.

// Optimal solution with O(n + m) complexity
// This approach involves using a hash map to store the nodes of the original graph and their corresponding clones.
// We can then iterate over the edges of the original graph and add the corresponding edges to the cloned graph.

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node(int _val) : val(_val) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        std::unordered_map<Node*, Node*> visited;
        return clone(node, visited);
    }

    Node* clone(Node* node, std::unordered_map<Node*, Node*>& visited) {
        if (visited.find(node) != visited.end()) return visited[node];

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(clone(neighbor, visited));
        }

        return cloneNode;
    }
};

int main() {
    // Test case 1:
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->neighbors = {node2, node3};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node1, node2};

    Solution solution;
    Node* clonedNode1 = solution.cloneGraph(node1);

    // Test case 2:
    Node* node4 = new Node(1);
    Node* node5 = new Node(2);
    node4->neighbors = {node5};
    node5->neighbors = {node4};

    Node* clonedNode4 = solution.cloneGraph(node4);

    // Test case 3:
    Node* node6 = new Node(1);

    Node* clonedNode6 = solution.cloneGraph(node6);

    return 0;
}
```