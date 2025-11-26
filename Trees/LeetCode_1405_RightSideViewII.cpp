```cpp
// LeetCode problem 1405: Longest Happy String
// https://leetcode.com/problems/longest-happy-string/
// Given a string s, return the longest happy string that can be formed by deleting some characters from s.
// A happy string is a string that:
//  - is empty ("")
//  - has only one character (e.g. "a")
//  - can be written as X + Y with X and Y being two happy strings

// Brute force approach with O(2^n) complexity
// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         string res;
//         dfs(res, a, b, c);
//         return res;
//     }
// private:
//     void dfs(string& res, int a, int b, int c) {
//         if (a > 0) {
//             res += 'a';
//             dfs(res, a - 1, b, c);
//             res.pop_back();
//         }
//         if (b > 0) {
//             res += 'b';
//             dfs(res, a, b - 1, c);
//             res.pop_back();
//         }
//         if (c > 0) {
//             res += 'c';
//             dfs(res, a, b, c - 1);
//             res.pop_back();
//         }
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> pq = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (!pq.empty()) {
            sort(pq.rbegin(), pq.rend());
            auto [cnt, ch] = pq[0];
            if (res.size() >= 2 && res.back() == res[res.size() - 2] && res.back() == ch) {
                if (pq.size() == 1) break;
                auto [cnt2, ch2] = pq[1];
                res += ch2;
                pq[1].first--;
                if (pq[1].first == 0) pq.erase(pq.begin() + 1);
            } else {
                res += ch;
                pq[0].first--;
                if (pq[0].first == 0) pq.erase(pq.begin());
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.longestDiverseString(1, 1, 7) << endl;  // "ccaccbcc"
    cout << solution.longestDiverseString(2, 2, 1) << endl;  // "aabbc"
    cout << solution.longestDiverseString(7, 1, 0) << endl;  // "aabaa"
    return 0;
}
```