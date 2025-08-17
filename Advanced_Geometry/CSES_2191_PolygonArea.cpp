/**
 * Problem: Polygon Area (CSES 2191)
 * Link: https://cses.fi/problemset/task/2191
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Shoelace Formula) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
void solve() {
    int n;
    // cin >> n;
    vector<pair<long long, long long>> p(n);
    // for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
    
    long long area = 0;
    for (int i = 0; i < n; i++) {
        area += (p[i].first * p[(i + 1) % n].second - p[(i + 1) % n].first * p[i].second);
    }
    // cout << abs(area) << endl; // Twice the area
}

int main() {
    // solve();
    return 0;
}










