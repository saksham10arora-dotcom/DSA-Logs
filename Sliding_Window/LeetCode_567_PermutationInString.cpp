```cpp
// LeetCode problem 567: Permutation In String, https://leetcode.com/problems/permutation-in-string/
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1, otherwise return false.

// Brute force approach: generate all permutations of s1 and check if any of them is a substring of s2, O(n! * m) complexity
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         vector<string> perms;
//         permute(s1, 0, perms);
//         for (const auto& perm : perms) {
//             if (s2.find(perm) != string::npos) return true;
//         }
//         return false;
//     }
// private:
//     void permute(string s, int start, vector<string>& perms) {
//         if (start == s.size() - 1) {
//             perms.push_back(s);
//         } else {
//             for (int i = start; i < s.size(); i++) {
//                 swap(s[start], s[i]);
//                 permute(s, start + 1, perms);
//                 swap(s[start], s[i]);
//             }
//         }
//     }
// };

// Optimal solution: use sliding window and frequency count, O(m) complexity
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> count1(26), count2(26);
        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            count2[s2[i] - 'a']++;
            if (i >= s1.size()) {
                count2[s2[i - s1.size()] - 'a']--;
            }
            if (i >= s1.size() - 1 && count1 == count2) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << boolalpha;
    cout << solution.checkInclusion("ab", "eidbaooo") << endl;  // true
    cout << solution.checkInclusion("ab", "eidboaoo") << endl;  // false
    cout << solution.checkInclusion("abc", "eidbaooo") << endl;  // false
    return 0;
}
```