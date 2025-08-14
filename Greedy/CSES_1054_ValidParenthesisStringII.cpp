```cpp
// Problem: Valid Parenthesis String II
// Link: https://cses.fi/problemset/task/1054
// Description: Given a string of parentheses, determine if it is valid.

#include <iostream>
#include <stack>
#include <string>

// Brute force approach: Generate all possible valid parenthesis strings and check if the given string is among them (O(2^n) complexity)
// However, this approach is inefficient and not practical for large inputs.

// Optimal solution: Use a stack to keep track of the opening parentheses and check if the corresponding closing parentheses are present (O(n) complexity)
bool isValid(const std::string& s) {
    std::stack<char> stack;
    for (char c : s) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.empty()) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isValid("()") << std::endl;  // True
    std::cout << isValid(")(") << std::endl;  // False
    std::cout << isValid("((()))") << std::endl;  // True
    return 0;
}
```