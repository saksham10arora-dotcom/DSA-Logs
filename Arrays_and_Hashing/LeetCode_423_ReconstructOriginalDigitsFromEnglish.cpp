```cpp
// LeetCode problem 423: Reconstruct Original Digits From English
// https://leetcode.com/problems/reconstruct-original-digits-from-english/
// Given a string s containing an out-of-order English representation of digits from 0 to 9, 
// return the digits in the correct order.

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    // Brute force approach with O(10!) complexity
    // std::string originalDigits(std::string s) {
    //     // Generate all permutations of digits from 0 to 9
    //     // Check if the permutation matches the given string
    //     // Return the first matching permutation
    // }

    // Optimal solution with O(n) complexity
    std::string originalDigits(std::string s) {
        std::unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }

        std::unordered_map<int, std::string> digits = {
            {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
            {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}
        };

        std::unordered_map<char, int> uniqueChars = {
            {'z', 0}, {'w', 2}, {'u', 4}, {'x', 6}, {'g', 8},
            {'o', 1}, {'h', 3}, {'f', 5}, {'s', 7}, {'i', 9}
        };

        std::string result;
        for (auto& pair : uniqueChars) {
            int digit = pair.second;
            std::string word = digits[digit];
            int freq = count[pair.first];

            for (int i = 0; i < freq; i++) {
                result += std::to_string(digit);
            }

            for (char c : word) {
                count[c] -= freq;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.originalDigits("owoztneoer") << std::endl;  // Output: "012"
    std::cout << solution.originalDigits("fviefuro") << std::endl;  // Output: "45"
    std::cout << solution.originalDigits("zero") << std::endl;  // Output: "0"
    return 0;
}
```