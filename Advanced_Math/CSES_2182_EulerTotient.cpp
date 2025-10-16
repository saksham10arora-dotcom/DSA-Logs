/**
 * Problem: Coprime Integers (CSES 2182)
 * Link: https://cses.fi/problemset/task/2182
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// --- Optimal Solution (Euler's Totient Sieve) ---
// Time Complexity: O(N log log N)
// Space Complexity: O(N)
vector<int> phiSieve(int n) {
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int main() {
    // int n; cin >> n;
    // vector<int> res = phiSieve(n);
    // cout << res[n] << endl;
    return 0;
}












