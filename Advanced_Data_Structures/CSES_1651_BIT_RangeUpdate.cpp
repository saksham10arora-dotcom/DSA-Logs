/**
 * Problem: Range Update Queries (CSES 1651)
 * Link: https://cses.fi/problemset/task/1651
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Binary Indexed Tree - Difference Array) ---
// Time Complexity: O(log N) for update and query
// Space Complexity: O(N)
class BIT {
    vector<long long> tree;
    int n;
public:
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, long long delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main() {
    // int n, q; cin >> n >> q;
    // vector<int> a(n);
    // BIT bit(n);
    // for(int i=0; i<n; i++) { cin >> a[i]; bit.update(i+1, a[i]); bit.update(i+2, -a[i]); }
    // while(q--) {
    //     int type; cin >> type;
    //     if(type == 1) {
    //         int l, r, u; cin >> l >> r >> u;
    //         bit.update(l, u); bit.update(r+1, -u);
    //     } else {
    //         int k; cin >> k; cout << bit.query(k) << endl;
    //     }
    // }
    return 0;
}














