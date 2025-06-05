/**
 * Problem: Array Division (CSES 1085)
 * Link: https://cses.fi/problemset/task/1085
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Binary Search on Answer) ---
// Time Complexity: O(N log(Sum))
// Space Complexity: O(N)
bool check(long long mid, int k, const vector<int>& a) {
    int count = 1;
    long long currentSum = 0;
    for (int x : a) {
        if (x > mid) return false;
        if (currentSum + x > mid) {
            count++;
            currentSum = x;
        } else {
            currentSum += x;
        }
    }
    return count <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        high += a[i];
        low = max(low, (long long)a[i]);
    }

    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, k, a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    // solve();
    return 0;
}


































