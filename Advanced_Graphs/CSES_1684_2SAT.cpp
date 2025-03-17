/**
 * Problem: Giant Pizza (CSES 1684)
 * Link: https://cses.fi/problemset/task/1684
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// --- Optimal Solution (2-SAT using Kosaraju's Algorithm) ---
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
struct TwoSAT {
    int n;
    vector<vector<int>> adj, radj;
    vector<int> component;
    vector<bool> visited;
    stack<int> order;

    TwoSAT(int n) : n(n), adj(2 * n), radj(2 * n), component(2 * n), visited(2 * n) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    // (a or b)
    void add_clause(int i, bool i_val, int j, bool j_val) {
        add_edge(2 * i + (i_val ? 0 : 1), 2 * j + (j_val ? 1 : 0));
        add_edge(2 * j + (j_val ? 0 : 1), 2 * i + (i_val ? 1 : 0));
    }
};

int main() {
    return 0;
}












