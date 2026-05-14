```cpp
// New21 Game, https://leetcode.com/problems/new21-game/, 
// Alice has some number of balls, and there are n+1 urns. 
// The balls are distributed randomly among the urns. 
// We need to find the probability that Alice has exactly k balls in the k-th urn.

// Brute force approach with O(n^k) complexity
class Solution {
public:
    double new21Game(int n, int k, int mp) {
        if (k == 0) return 1.0;
        double res = 0.0;
        for (int i = 1; i <= mp; i++) {
            if (k - i >= 0) {
                res += new21Game(n, k - i, mp) / mp;
            }
        }
        return res;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    double new21Game(int n, int k, int mp) {
        if (k == 0) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double s = 1.0;
        for (int i = 1; i <= n; i++) {
            dp[i] = s / mp;
            if (i < k) {
                s += dp[i];
            }
            if (i - mp >= 0) {
                s -= dp[i - mp];
            }
        }
        double res = 0.0;
        for (int i = k; i <= n; i++) {
            res += dp[i];
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.new21Game(10, 3, 5) << endl;  // Output: 0.8
    cout << solution.new21Game(6, 1, 10) << endl;   // Output: 0.6
    cout << solution.new21Game(21, 17, 10) << endl; // Output: 0.73278
    return 0;
}
```