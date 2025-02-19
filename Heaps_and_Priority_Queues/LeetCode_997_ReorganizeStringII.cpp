```cpp
// LeetCode problem 997: Reorganize String
// https://leetcode.com/problems/reorganize-string/
// Given a string s, reorganize the characters so that no two adjacent characters are the same.
// If it is impossible to reorganize the string, return an empty string.

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

// Brute force approach: try all possible permutations of the string and check if any of them satisfy the condition
// O(n!) time complexity, O(n) space complexity
// string reorganizeStringBruteForce(string s) {
//     // ...
// }

// Optimal solution: use a priority queue to store the characters and their frequencies
// O(n log n) time complexity, O(n) space complexity
string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto& p : freq) {
        pq.push({p.second, p.first});
    }

    string res;
    while (!pq.empty()) {
        auto p1 = pq.top();
        pq.pop();
        if (!res.empty() && res.back() == p1.second) {
            if (pq.empty()) {
                return "";
            }
            auto p2 = pq.top();
            pq.pop();
            res += p2.second;
            if (--p2.first > 0) {
                pq.push(p2);
            }
            pq.push(p1);
        } else {
            res += p1.second;
            if (--p1.first > 0) {
                pq.push(p1);
            }
        }
    }
    return res;
}

int main() {
    cout << reorganizeString("aab") << endl;  // "aba"
    cout << reorganizeString("aaab") << endl;  // ""
    cout << reorganizeString("vvvlo") << endl;  // "vlvov"
    return 0;
}
```