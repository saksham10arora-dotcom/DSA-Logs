```cpp
// LeetCode problem 2673: Decode String I I I
// https://leetcode.com/problems/decode-string-iii/
// Given a string s, return the decoded string.

#include <iostream>
#include <string>
#include <stack>

// Brute force approach with O(n) complexity
class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<std::string> stack;
        std::string res;
        int multi = 0;
        for (char c : s) {
            if (c == '[') {
                stack.push(res);
                stack.push(std::to_string(multi));
                res = "";
                multi = 0;
            } else if (c == ']') {
                std::string str = stack.top();
                stack.pop();
                int count = std::stoi(stack.top());
                stack.pop();
                while (count--) {
                    str += res;
                }
                res = str;
            } else if (c >= '0' && c <= '9') {
                multi = multi * 10 + c - '0';
            } else {
                res += c;
            }
        }
        return res;
    }
};

// Optimal solution with O(n) complexity
// The above solution is already optimal

int main() {
    Solution solution;
    std::cout << solution.decodeString("abc") << std::endl;  // "abc"
    std::cout << solution.decodeString("3[a]2[bc]") << std::endl;  // "aaabcbc"
    std::cout << solution.decodeString("3[a2[c]]") << std::endl;  // "accaccacc"
    return 0;
}
```