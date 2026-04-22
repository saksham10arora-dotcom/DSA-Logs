```cpp
// Generate Parentheses Variant, https://cses.fi/problemset/task/1190
// Generate all possible combinations of well-formed parentheses with a given number of pairs.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: generate all possible combinations of parentheses and check if they are well-formed (O(2^(2n)))
void generateParenthesesBruteForce(int n, std::string current, int open, int close, std::vector<std::string>& result) {
    if (current.size() == 2 * n) {
        int count = 0;
        bool valid = true;
        for (char c : current) {
            if (c == '(') {
                count++;
            } else {
                count--;
                if (count < 0) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid && count == 0) {
            result.push_back(current);
        }
        return;
    }
    generateParenthesesBruteForce(n, current + "(", open + 1, close, result);
    generateParenthesesBruteForce(n, current + ")", open, close + 1, result);
}

// Optimal solution: use backtracking to generate only well-formed combinations (O(4^n / n^(3/2)))
void generateParenthesesOptimal(int n, std::string current, int open, int close, std::vector<std::string>& result) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        generateParenthesesOptimal(n, current + "(", open + 1, close, result);
    }
    if (close < open) {
        generateParenthesesOptimal(n, current + ")", open, close + 1, result);
    }
}

int main() {
    int n;
    std::vector<std::string> result;

    n = 2;
    result.clear();
    generateParenthesesOptimal(n, "", 0, 0, result);
    std::cout << "Test case 1: n = " << n << std::endl;
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }

    n = 3;
    result.clear();
    generateParenthesesOptimal(n, "", 0, 0, result);
    std::cout << "\nTest case 2: n = " << n << std::endl;
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }

    n = 1;
    result.clear();
    generateParenthesesOptimal(n, "", 0, 0, result);
    std::cout << "\nTest case 3: n = " << n << std::endl;
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }

    return 0;
}
```