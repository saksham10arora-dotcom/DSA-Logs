```cpp
// LeetCode problem 225: Super Pow Variant
// https://leetcode.com/problems/super-pow/
// Your task is to calculate a^(b^c) % k.

class Solution {
public:
    // Brute force approach with O(b^c) complexity
    int superPowBruteForce(int a, vector<int>& b, int k) {
        long long res = 1;
        for (int i : b) {
            res = powMod(res, 10, k) * i % k;
        }
        return powMod(a, res, k);
    }

    // Optimal solution with O(log(b^c)) complexity
    int superPow(int a, vector<int>& b, int k) {
        long long res = 1;
        for (int i : b) {
            res = res * 10 + i;
            res %= (k - 1);
        }
        return powMod(a, res, k);
    }

    long long powMod(long long a, long long b, int k) {
        long long res = 1;
        a %= k;
        while (b > 0) {
            if (b & 1) res = res * a % k;
            a = a * a % k;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> b1 = {3};
    vector<int> b2 = {1, 0};
    vector<int> b3 = {2, 0, 0};
    cout << solution.superPow(2, b1, 11) << endl;  // Output: 8
    cout << solution.superPow(2, b2, 3) << endl;  // Output: 0
    cout << solution.superPow(2, b3, 5) << endl;  // Output: 3
    return 0;
}
```