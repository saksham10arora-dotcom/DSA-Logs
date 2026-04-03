```cpp
// LeetCode problem 43: Multiply Strings
// https://leetcode.com/problems/multiply-strings/
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

#include <iostream>
#include <string>
#include <vector>

// Brute force approach: O(n*m) where n and m are lengths of num1 and num2 respectively
class Solution_BruteForce {
public:
    std::string multiply(std::string num1, std::string num2) {
        long long n1 = std::stoll(num1);
        long long n2 = std::stoll(num2);
        return std::to_string(n1 * n2);
    }
};

// Optimal solution: O(n*m) where n and m are lengths of num1 and num2 respectively
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int n1 = num1.size(), n2 = num2.size();
        std::vector<int> pos(n1 + n2, 0);
        
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];
                
                pos[p1] += sum / 10;
                pos[p2] = sum % 10;
            }
        }
        
        std::string res = "";
        for (int value : pos) {
            if (!(res == "" && value == 0)) {
                res += std::to_string(value);
            }
        }
        return res == "" ? "0" : res;
    }
};

int main() {
    Solution solution;
    std::cout << solution.multiply("123", "456") << std::endl;  // Output: "56088"
    std::cout << solution.multiply("2", "3") << std::endl;      // Output: "6"
    std::cout << solution.multiply("0", "123") << std::endl;     // Output: "0"
    return 0;
}
```