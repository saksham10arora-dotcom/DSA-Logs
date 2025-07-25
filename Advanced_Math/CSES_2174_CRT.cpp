/**
 * Problem: Chinese Remainder Theorem (CSES 2174)
 * Link: https://cses.fi/problemset/task/2174
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// --- Optimal Solution (Extended Euclidean Algorithm) ---
// Time Complexity: O(log(min(A, B)))
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = extgcd(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    return 0;
}









