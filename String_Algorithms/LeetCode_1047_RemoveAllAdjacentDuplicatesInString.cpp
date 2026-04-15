```cpp
// LeetCode problem 1047: Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
// We repeatedly make duplicate removals on S until no more duplicate removals can be made.
// Return the final string after all such duplicate removals have been made.

#include <iostream>
#include <string>
#include <stack>

// Brute force approach with O(n^2) complexity
// std::string removeDuplicatesBruteForce(std::string S) {
//     bool changed;
//     do {
//         changed = false;
//         for (int i = 0; i < S.size() - 1; ++i) {
//             if (S[i] == S[i + 1]) {
//                 S.erase(i, 2);
//                 changed = true;
//                 break;
//             }
//         }
//     } while (changed);
//     return S;
// }

// Optimal solution with O(n) complexity
std::string removeDuplicates(std::string S) {
    std::stack<char> stack;
    for (char c : S) {
        if (!stack.empty() && stack.top() == c) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }
    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }
    return result;
}

int main() {
    std::cout << removeDuplicates("abbaca") << std::endl;  // "ca"
    std::cout << removeDuplicates("azxxzy") << std::endl;  // "ay"
    std::cout << removeDuplicates("a") << std::endl;       // "a"
    return 0;
}
```