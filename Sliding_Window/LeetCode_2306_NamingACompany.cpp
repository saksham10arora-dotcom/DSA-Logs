```cpp
// Naming A Company, https://leetcode.com/problems/naming-a-company/, 
// Given an array of strings ideas, return the number of families of companies that can be named.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Brute force approach with O(n^2 * m) complexity
class Solution {
public:
    long long numberOfNames(std::vector<std::string>& ideas) {
        int n = ideas.size();
        std::unordered_set<std::string> set;
        for (const auto& idea : ideas) {
            set.insert(idea);
        }
        long long count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::string s1 = ideas[i];
                std::string s2 = ideas[j];
                std::string s3 = s1;
                s3[0] = s2[0];
                if (set.find(s3) == set.end()) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> ideas1 = {"coffee","donuts","time","toffee"};
    std::cout << solution.numberOfNames(ideas1) << std::endl;  // Output: 6

    std::vector<std::string> ideas2 = {"lack","back"};
    std::cout << solution.numberOfNames(ideas2) << std::endl;  // Output: 0

    return 0;
}
```