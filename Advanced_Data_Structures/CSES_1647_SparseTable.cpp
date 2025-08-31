/**
 * Problem: Static Range Minimum Queries (CSES 1647)
 * Link: https://cses.fi/problemset/task/1647
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Sparse Table) ---
// Time Complexity: O(N log N) build, O(1) query
// Space Complexity: O(N log N)
class SparseTable {
    vector<vector<int>> st;
    vector<int> logs;
public:
    SparseTable(vector<int>& arr) {
        int n = arr.size();
        int k = 31 - __builtin_clz(n);
        st.assign(k + 1, vector<int>(n));
        logs.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) logs[i] = logs[i/2] + 1;
        
        for (int i = 0; i < n; i++) st[0][i] = arr[i];
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }
    
    int query(int l, int r) {
        int j = logs[r - l + 1];
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

int main() {
    // int n, q; cin >> n >> q;
    // vector<int> a(n); for(int &x : a) cin >> x;
    // SparseTable st(a);
    // while(q--) { int l, r; cin >> l >> r; cout << st.query(l-1, r-1) << endl; }
    return 0;
}










