/**
 * Problem: Road Reparation (CSES 1675)
 * Link: https://cses.fi/problemset/task/1675
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

// --- Optimal Solution (Kruskal's Algorithm - Greedy) ---
// Time Complexity: O(E log E)
// Space Complexity: O(V + E)
void solve() {
    int n, m;
    // cin >> n >> m;
    vector<Edge> edges;
    // for (int i = 0; i < m; i++) {
    //     int u, v, w; cin >> u >> v >> w;
    //     edges.push_back({u, v, w});
    // }
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    long long mstWeight = 0;
    int count = 0;
    for (auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.w;
            count++;
        }
    }
    
    // if (count == n - 1) cout << mstWeight << endl;
    // else cout << "IMPOSSIBLE" << endl;
}

int main() {
    // solve();
    return 0;
}



















