```cpp
// LeetCode problem 2422: Decode String I I I, https://leetcode.com/problems/decode-string-iii/
// Given a string s, decode it and return the decoded string.

#include <iostream>
#include <stack>
#include <string>

// Brute force approach with O(n) complexity
class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<std::string> strStack;
        std::stack<int> numStack;
        std::string res = "";
        int num = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                strStack.push(res);
                numStack.push(num);
                res = "";
                num = 0;
            } else if (c == ']') {
                std::string temp = res;
                res = strStack.top();
                strStack.pop();
                int count = numStack.top();
                numStack.pop();
                while (count--) {
                    res += temp;
                }
            } else {
                res += c;
            }
        }
        return res;
    }
};

// Optimal solution with O(n) complexity
// The above solution is already optimal with O(n) complexity

int main() {
    Solution solution;
    std::cout << solution.decodeString("3[a]2[bc]") << std::endl;  // Output: "aaabcbc"
    std::cout << solution.decodeString("3[a2[c]]") << std::endl;  // Output: "accaccacc"
    std::cout << solution.decodeString("2[abc]3[cd]ef") << std::endl;  // Output: "abcabccdcdcdef"
    return 0;
}
```