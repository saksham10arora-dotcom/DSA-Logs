/**
 * Problem: Bit++ (Codeforces 282A)
 * Link: https://codeforces.com/problemset/problem/282/A
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- Optimal Solution ---
// Time Complexity: O(N)
// Space Complexity: O(1)
void solve() {
    int n;
    cin >> n;
    int x = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s[1] == '+') x++;
        else x--;
    }
    cout << x << endl;
}

int main() {
    // Note: Codeforces problems usually read from stdin
    // solve();
    return 0;
}





























