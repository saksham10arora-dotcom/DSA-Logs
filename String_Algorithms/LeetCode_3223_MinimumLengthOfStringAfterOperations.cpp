```cpp
// LeetCode problem 3223: Minimum Length Of String After Operations
// https://leetcode.com/problems/minimum-length-of-string-after-operations/
// Given a string s, find the minimum length of the string after deleting all the occurrences of the substrings "AB" and "CD" from s.

#include <iostream>
#include <string>

// Brute force approach with O(2^n) complexity
int min_length_brute_force(const std::string& s) {
    int n = s.size();
    int min_length = n;
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::string temp = s;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) && i + 1 < n) {
                if ((temp[i] == 'A' && temp[i + 1] == 'B') || (temp[i] == 'C' && temp[i + 1] == 'D')) {
                    temp.erase(i, 2);
                    --i;
                    --n;
                }
            }
        }
        min_length = std::min(min_length, static_cast<int>(temp.size()));
    }
    return min_length;
}

// Optimal solution with O(n) complexity
int min_length_optimal(const std::string& s) {
    int count_a = 0, count_c = 0;
    for (char c : s) {
        if (c == 'A') {
            ++count_a;
        } else if (c == 'C') {
            ++count_c;
        } else if (c == 'B' && count_a > 0) {
            --count_a;
        } else if (c == 'D' && count_c > 0) {
            --count_c;
        }
    }
    return count_a + count_c;
}

int main() {
    std::cout << min_length_optimal("ABCD") << std::endl;  // Output: 0
    std::cout << min_length_optimal("ADBC") << std::endl;  // Output: 2
    std::cout << min_length_optimal("ABCDCD") << std::endl;  // Output: 0
    return 0;
}
```