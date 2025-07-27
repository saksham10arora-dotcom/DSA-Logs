/**
 * Problem: Valid Parentheses (LeetCode 20)
 * Link: https://leetcode.com/problems/valid-parentheses/
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// --- Optimal Solution (Stack) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "()[]{}";
    cout << (isValid(s) ? "True" : "False") << endl;
    return 0;
}


















