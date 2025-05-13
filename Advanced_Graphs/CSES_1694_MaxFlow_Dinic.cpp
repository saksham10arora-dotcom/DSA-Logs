/**
 * Problem: Download Speed (CSES 1694)
 * Link: https://cses.fi/problemset/task/1694
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Dinic's Algorithm - Max Flow) ---
// Time Complexity: O(V^2 E)
// Space Complexity: O(V + E)
struct Edge {
    int to, rev;
    long long cap;
};

vector<vector<Edge>> adj;
vector<int> level, ptr;

bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto& edge : adj[v]) {
            if (edge.cap > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

long long dfs(int v, int t, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < adj[v].size(); cid++) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.cap == 0) continue;
        long long tr_pushed = dfs(tr, t, min(pushed, edge.cap));
        if (tr_pushed == 0) continue;
        edge.cap -= tr_pushed;
        adj[tr][edge.rev].cap += tr_pushed;
        return tr_pushed;
    }
    return 0;
}

int main() {
    return 0;
}










