```cpp
// LeetCode problem 2457: Minimum Addition To Make Integer Beautiful
// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/
// Given an integer n, find the minimum number of operations required to make n a beautiful number.
// A beautiful number is a number whose digits sum up to a number that is at most 20.

// Brute force approach: try all possible numbers and check if they are beautiful
// O(10^10) complexity, not efficient for large inputs
// int makeBeautiful(int n) {
//     int count = 0;
//     while (true) {
//         if (isBeautiful(n)) return count;
//         n++;
//         count++;
//     }
// }

// Optimal solution: use a queue to keep track of the numbers to be processed
// O(log n) complexity, efficient for large inputs
class Solution {
public:
    int makeBeautiful(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 10 > 5) {
                count += 10 - n % 10;
                n /= 10;
                n++;
            } else {
                n /= 10;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::cout << solution.makeBeautiful(16) << std::endl;  // Output: 4
    std::cout << solution.makeBeautiful(2) << std::endl;   // Output: 0
    std::cout << solution.makeBeautiful(46) << std::endl;  // Output: 4
    return 0;
}
```