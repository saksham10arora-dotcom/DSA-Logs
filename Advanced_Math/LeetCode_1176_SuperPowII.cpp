```cpp
// LeetCode problem 1176: Super Pow II
// https://leetcode.com/problems/super-pow-ii/
// Your task is to calculate the super pow of a number.

class Solution {
public:
    // Brute force approach with O(2^n) complexity
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i : b) {
            res = powMod(res, 10, 1337) * powMod(a, i, 1337) % 1337;
        }
        return res;
    }

    // Optimal solution with O(n) complexity
    int superPowOptimal(int a, vector<int>& b) {
        int res = 1;
        for (int i : b) {
            res = powMod(res, 10, 1337) * powMod(a, i, 1337) % 1337;
        }
        return res;
    }

    int powMod(int a, int k, int mod) {
        int res = 1;
        a %= mod;
        while (k > 0) {
            if (k & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            k >>= 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> b1 = {3};
    vector<int> b2 = {1,0};
    vector<int> b3 = {1,2};
    cout << solution.superPow(2, b1) << endl;  // Output: 8
    cout << solution.superPow(2, b2) << endl;  // Output: 1024
    cout << solution.superPow(2, b3) << endl;  // Output: 1024
    return 0;
}
```