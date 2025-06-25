/**
 * Problem: Books (Codeforces 279B)
 * Link: https://codeforces.com/problemset/problem/279/B
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Two Pointers / Sliding Window) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = 0, sum = 0, maxBooks = 0;
    while (right < n) {
        sum += a[right];
        while (sum > t) {
            sum -= a[left];
            left++;
        }
        maxBooks = max(maxBooks, right - left + 1);
        right++;
    }
    cout << maxBooks << endl;
}

int main() {
    // solve();
    return 0;
}































