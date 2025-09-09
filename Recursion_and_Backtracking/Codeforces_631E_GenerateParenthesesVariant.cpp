```cpp
// Codeforces_631E_GenerateParenthesesVariant, https://codeforces.com/contest/631/problem/E
// Generate all possible valid parentheses sequences of length 2n with a given number of opening and closing parentheses.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: generate all possible sequences and check if they are valid (O(2^(2n)))
std::vector<std::string> generateParenthesesBruteForce(int n, int open, int close) {
    std::vector<std::string> result;
    std::string current = "";
    generateBruteForce(result, current, n, open, close, 0, 0);
    return result;
}

void generateBruteForce(std::vector<std::string>& result, std::string current, int n, int open, int close, int openCount, int closeCount) {
    if (current.size() == 2 * n) {
        if (openCount == open && closeCount == close) {
            result.push_back(current);
        }
        return;
    }
    if (openCount < open) {
        generateBruteForce(result, current + "(", n, open, close, openCount + 1, closeCount);
    }
    if (closeCount < close && closeCount < openCount) {
        generateBruteForce(result, current + ")", n, open, close, openCount, closeCount + 1);
    }
}

// Optimal solution: use recursion and backtracking to generate only valid sequences (O(4^n / n^(3/2)))
std::vector<std::string> generateParenthesesOptimal(int n, int open, int close) {
    std::vector<std::string> result;
    std::string current = "";
    generateOptimal(result, current, n, open, close, 0, 0);
    return result;
}

void generateOptimal(std::vector<std::string>& result, std::string current, int n, int open, int close, int openCount, int closeCount) {
    if (current.size() == 2 * n) {
        if (openCount == open && closeCount == close) {
            result.push_back(current);
        }
        return;
    }
    if (openCount < open) {
        generateOptimal(result, current + "(", n, open, close, openCount + 1, closeCount);
    }
    if (closeCount < close && closeCount < openCount) {
        generateOptimal(result, current + ")", n, open, close, openCount, closeCount + 1);
    }
}

int main() {
    std::vector<std::string> result1 = generateParenthesesOptimal(3, 3, 3);
    for (const auto& str : result1) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> result2 = generateParenthesesOptimal(2, 2, 2);
    for (const auto& str : result2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> result3 = generateParenthesesOptimal(1, 1, 1);
    for (const auto& str : result3) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
```