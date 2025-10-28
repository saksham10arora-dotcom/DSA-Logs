/**
 * Problem: Sereja and Dima (Codeforces 381A)
 * Link: https://codeforces.com/contest/381/problem/A
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Two Pointers) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = n - 1;
    int s = 0, d = 0;
    bool turn = true; // true for Sereja, false for Dima

    while (left <= right) {
        if (a[left] > a[right]) {
            if (turn) s += a[left];
            else d += a[left];
            left++;
        } else {
            if (turn) s += a[right];
            else d += a[right];
            right--;
        }
        turn = !turn;
    }
    cout << s << " " << d << endl;
}

int main() {
    // solve();
    return 0;
}






















