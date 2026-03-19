```cpp
// LeetCode problem 537: Complex Number Multiplication
// https://leetcode.com/problems/complex-number-multiplication/
// Given two complex numbers, return their product.

// Brute force approach: O(1) complexity
// class Solution {
// public:
//     string complexNumberMultiply(string a, string b) {
//         int realA, imagA, realB, imagB;
//         sscanf(a.c_str(), "%d+%di", &realA, &imagA);
//         sscanf(b.c_str(), "%d+%di", &realB, &imagB);
//         int real = realA * realB - imagA * imagB;
//         int imag = realA * imagB + realB * imagA;
//         return to_string(real) + "+" + to_string(imag) + "i";
//     }
// };

// Optimal solution: O(1) complexity
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int realA, imagA, realB, imagB;
        sscanf(a.c_str(), "%d+%di", &realA, &imagA);
        sscanf(b.c_str(), "%d+%di", &realB, &imagB);
        int real = realA * realB - imagA * imagB;
        int imag = realA * imagB + realB * imagA;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};

int main() {
    Solution solution;
    printf("%s\n", solution.complexNumberMultiply("1+1i", "1+1i").c_str());  // Output: "0+2i"
    printf("%s\n", solution.complexNumberMultiply("1+2i", "1+3i").c_str());  // Output: "-5+5i"
    printf("%s\n", solution.complexNumberMultiply("1+2i", "2+3i").c_str());  // Output: "-4+7i"
    return 0;
}
```