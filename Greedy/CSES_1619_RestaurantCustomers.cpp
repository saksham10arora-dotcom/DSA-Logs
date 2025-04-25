/**
 * Problem: Restaurant Customers (CSES 1619)
 * Link: https://cses.fi/problemset/task/1619
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Greedy Coordinate Compression Idea) ---
// Time Complexity: O(N log N)
// Space Complexity: O(N)
void solve() {
    int n;
    // cin >> n;
    vector<pair<int, int>> events;
    // for (int i = 0; i < n; i++) {
    //     int a, b; cin >> a >> b;
    //     events.push_back({a, 1}); // Arrival
    //     events.push_back({b, -1}); // Departure
    // }
    sort(events.begin(), events.end());
    
    int current = 0, maxC = 0;
    for (auto& e : events) {
        current += e.second;
        maxC = max(maxC, current);
    }
    // cout << maxC << endl;
}

int main() {
    // solve();
    return 0;
}
















