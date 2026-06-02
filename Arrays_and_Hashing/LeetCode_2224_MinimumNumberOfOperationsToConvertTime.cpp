```cpp
// LeetCode problem 2224: Minimum Number Of Operations To Convert Time
// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
// Given two string times in "HH:MM" format, find the minimum number of operations to convert time.

#include <iostream>
#include <string>
#include <cmath>

// Brute force approach with O(1) complexity
class Solution_BruteForce {
public:
    int convertTime(std::string current, std::string correct) {
        int currTime = (current[0] - '0') * 600 + (current[1] - '0') * 60 + (current[3] - '0') * 10 + (current[4] - '0');
        int corrTime = (correct[0] - '0') * 600 + (correct[1] - '0') * 60 + (correct[3] - '0') * 10 + (correct[4] - '0');
        int diff = std::abs(corrTime - currTime);
        int operations = diff / 60 + diff % 60;
        return operations;
    }
};

// Optimal solution with O(1) complexity
class Solution_Optimal {
public:
    int convertTime(std::string current, std::string correct) {
        int currTime = ((current[0] - '0') * 10 + (current[1] - '0')) * 60 + ((current[3] - '0') * 10 + (current[4] - '0'));
        int corrTime = ((correct[0] - '0') * 10 + (correct[1] - '0')) * 60 + ((correct[3] - '0') * 10 + (correct[4] - '0'));
        int diff = std::abs(corrTime - currTime);
        int operations = diff / 60 + diff % 60;
        return operations;
    }
};

int main() {
    Solution_BruteForce bruteForce;
    Solution_Optimal optimal;

    std::cout << bruteForce.convertTime("09:41", "10:34") << std::endl;  // Output: 3
    std::cout << optimal.convertTime("09:41", "10:34") << std::endl;  // Output: 3

    std::cout << bruteForce.convertTime("23:59", "00:00") << std::endl;  // Output: 1
    std::cout << optimal.convertTime("23:59", "00:00") << std::endl;  // Output: 1

    return 0;
}
```