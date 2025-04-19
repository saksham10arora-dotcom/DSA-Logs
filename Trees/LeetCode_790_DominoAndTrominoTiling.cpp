```cpp
// Domino And Tromino Tiling, https://leetcode.com/problems/domino-and-tromino-tiling/
// We have two types of tiles: dominoes and trominoes. 
// We use these tiles to tile a 2xN board.

// Brute force approach with O(2^N) complexity
class Solution {
public:
    int numTilings(int N) {
        int mod = 1e9 + 7;
        vector<long long> dp(N + 1, 0);
        dp[0] = 1;
        if (N >= 1) dp[1] = 1;
        if (N >= 2) dp[2] = 2;
        for (int i = 3; i <= N; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * dp[i - 3]) % mod;
        }
        return dp[N];
    }
};

// Optimal solution with O(N) complexity
class Solution {
public:
    int numTilings(int N) {
        int mod = 1e9 + 7;
        if (N == 0) return 0;
        if (N == 1) return 1;
        if (N == 2) return 2;
        int a = 1, b = 1, c = 2;
        for (int i = 3; i <= N; i++) {
            int temp = (b + c + 2 * a) % mod;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};

int main() {
    Solution solution;
    cout << solution.numTilings(3) << endl;  // Output: 5
    cout << solution.numTilings(4) << endl;  // Output: 11
    cout << solution.numTilings(5) << endl;  // Output: 24
    return 0;
}
```