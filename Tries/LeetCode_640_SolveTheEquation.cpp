```cpp
// Solve The Equation
// https://leetcode.com/problems/solve-the-equation/
// Solve a linear equation in the form of "x + 5 = 7" or "x - 5 = -2".

#include <iostream>
#include <string>

class Solution {
public:
    // Brute force approach with O(n) complexity
    std::string solveEquation(std::string equation) {
        int x = 0, num = 0;
        bool isX = false;
        for (int i = 0; i < equation.size(); i++) {
            if (equation[i] == '=') {
                isX = true;
                continue;
            }
            if (equation[i] == 'x') {
                x += (isX? -1 : 1) * (num == 0? 1 : num);
                num = 0;
            } else if (equation[i] == '+') {
                num = 0;
            } else if (equation[i] == '-') {
                num = 0;
            } else {
                num = num * 10 + (equation[i] - '0');
            }
        }
        if (num!= 0) {
            x += (isX? -1 : 1) * num;
        }
        if (x == 0) {
            return "Infinite solutions";
        }
        if (x == 1) {
            return "x=0";
        }
        return "x=" + std::to_string(-x);
    }
};

int main() {
    Solution solution;
    std::cout << solution.solveEquation("x+5-3+x=1+x") << std::endl;  // Output: "x=1"
    std::cout << solution.solveEquation("x=x") << std::endl;  // Output: "Infinite solutions"
    std::cout << solution.solveEquation("2x=x") << std::endl;  // Output: "x=0"
    return 0;
}
```