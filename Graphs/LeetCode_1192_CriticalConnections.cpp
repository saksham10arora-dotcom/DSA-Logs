/**
 * Problem: Critical Connections in a Network (LeetCode 1192)
 * Link: https://leetcode.com/problems/critical-connections-in-a-network/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Tarjan's Bridge-finding Algorithm) ---
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
void dfs(int u, int p, int& timer, vector<int>& disc, vector<int>& low, 
         vector<vector<int>>& adj, vector<vector<int>>& bridges) {
    disc[u] = low[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!disc[v]) {
            dfs(v, u, timer, disc, low, adj, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    for (auto& c : connections) {
        adj[c[0]].push_back(c[1]);
        adj[c[1]].push_back(c[0]);
    }
    vector<int> disc(n, 0), low(n, 0);
    vector<vector<int>> bridges;
    int timer = 0;
    dfs(0, -1, timer, disc, low, adj, bridges);
    return bridges;
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> res = criticalConnections(n, connections);
    for (auto& b : res) cout << b[0] << "-" << b[1] << endl;
    return 0;
}

















