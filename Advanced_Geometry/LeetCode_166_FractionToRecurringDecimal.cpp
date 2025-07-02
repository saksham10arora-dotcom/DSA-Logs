```cpp
// Fraction To Recurring Decimal, https://leetcode.com/problems/fraction-to-recurring-decimal/
// Given a numerator and a denominator, return the fraction as a decimal string.

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    // Brute force approach with O(n) complexity, where n is the number of digits in the decimal representation
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        std::string result;
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        long long num = std::abs((long long)numerator);
        long long den = std::abs((long long)denominator);
        result += std::to_string(num / den);
        long long remainder = num % den;
        if (remainder == 0) return result;
        result += ".";
        std::unordered_map<long long, int> map;
        while (remainder != 0 && map.find(remainder) == map.end()) {
            map[remainder] = result.size();
            remainder *= 10;
            result += std::to_string(remainder / den);
            remainder %= den;
        }
        if (remainder != 0) {
            int index = map[remainder];
            result.insert(index, 1, '(');
            result += ")";
        }
        return result;
    }

    // Optimal solution with O(log(n)) complexity, where n is the number of digits in the decimal representation
    std::string fractionToDecimalOptimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        std::string result;
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        long long num = std::abs((long long)numerator);
        long long den = std::abs((long long)denominator);
        result += std::to_string(num / den);
        long long remainder = num % den;
        if (remainder == 0) return result;
        result += ".";
        std::unordered_map<long long, int> map;
        while (remainder != 0 && map.find(remainder) == map.end()) {
            map[remainder] = result.size();
            remainder *= 10;
            result += std::to_string(remainder / den);
            remainder %= den;
        }
        if (remainder != 0) {
            int index = map[remainder];
            result.insert(index, 1, '(');
            result += ")";
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.fractionToDecimal(1, 2) << std::endl;  // Output: "0.5"
    std::cout << solution.fractionToDecimal(2, 3) << std::endl;  // Output: "0.(6)"
    std::cout << solution.fractionToDecimal(4, 11) << std::endl;  // Output: "0.(36)"
    std::cout << solution.fractionToDecimalOptimal(1, 2) << std::endl;  // Output: "0.5"
    std::cout << solution.fractionToDecimalOptimal(2, 3) << std::endl;  // Output: "0.(6)"
    std::cout << solution.fractionToDecimalOptimal(4, 11) << std::endl;  // Output: "0.(36)"
    return 0;
}
```