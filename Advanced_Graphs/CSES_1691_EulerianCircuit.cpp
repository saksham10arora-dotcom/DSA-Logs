/**
 * Problem: Mail Delivery (CSES 1691)
 * Link: https://cses.fi/problemset/task/1691
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

// --- Optimal Solution (Hierholzer's Algorithm - Eulerian Circuit) ---
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
void findEulerianCircuit() {
    int n, m;
    // cin >> n >> m;
    vector<set<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    // for(int i=0; i<m; i++) {
    //     int u, v; cin >> u >> v;
    //     adj[u].insert(v); adj[v].insert(u);
    //     degree[u]++; degree[v]++;
    // }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            // cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    stack<int> st;
    st.push(1);
    vector<int> res;
    while (!st.empty()) {
        int u = st.top();
        if (adj[u].empty()) {
            res.push_back(u);
            st.pop();
        } else {
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            st.push(v);
        }
    }
}

int main() {
    return 0;
}












