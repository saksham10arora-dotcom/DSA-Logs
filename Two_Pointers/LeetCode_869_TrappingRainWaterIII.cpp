```cpp
// LeetCode problem 869: Reordered Power of 2
// https://leetcode.com/problems/reordered-power-of-2/
// Given an integer N, return true if and only if it is a power of 2 that has been reordered.

// Brute force approach with O(2^N) complexity
// class Solution {
// public:
//     bool reorderedPowerOf2(int N) {
//         string str = to_string(N);
//         sort(str.begin(), str.end());
//         for (int i = 0; i < 30; i++) {
//             string power = to_string(1 << i);
//             sort(power.begin(), power.end());
//             if (str == power) return true;
//         }
//         return false;
//     }
// };

// Optimal solution with O(logN) complexity
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str = to_string(N);
        sort(str.begin(), str.end());
        for (int i = 0; i < 30; i++) {
            string power = to_string(1 << i);
            sort(power.begin(), power.end());
            if (str == power) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    // Test case 1
    int N1 = 16;
    bool result1 = solution.reorderedPowerOf2(N1);
    // Test case 2
    int N2 = 10;
    bool result2 = solution.reorderedPowerOf2(N2);
    // Test case 3
    int N3 = 46;
    bool result3 = solution.reorderedPowerOf2(N3);
    return 0;
}
```