/**
 * Problem: Team (Codeforces 231A)
 * Link: https://codeforces.com/problemset/problem/231/A
 */

#include <iostream>

using namespace std;

// --- Optimal Solution ---
// Time Complexity: O(N)
// Space Complexity: O(1)
void solve() {
    int n;
    cin >> n;
    int count = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) count++;
    }
    cout << count << endl;
}

int main() {
    // solve();
    return 0;
}





































