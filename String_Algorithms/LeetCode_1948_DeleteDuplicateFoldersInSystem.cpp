```cpp
// LeetCode problem 1948: Delete Duplicate Folders In System
// https://leetcode.com/problems/delete-duplicate-folders-in-system/
// Given a list of paths of a file system, return all the paths that should be deleted.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

// Brute force approach: O(n^2) time complexity, O(n) space complexity
// class Solution {
// public:
//     std::vector<std::string> deleteDuplicateFolder(std::vector<std::string>& paths) {
//         std::unordered_set<std::string> uniquePaths;
//         std::vector<std::string> result;
//         for (const auto& path : paths) {
//             if (uniquePaths.find(path) == uniquePaths.end()) {
//                 uniquePaths.insert(path);
//             } else {
//                 result.push_back(path);
//             }
//         }
//         return result;
//     }
// };

// Optimal solution: O(n) time complexity, O(n) space complexity
class Solution {
public:
    std::vector<std::string> deleteDuplicateFolder(std::vector<std::string>& paths) {
        std::unordered_map<std::string, int> pathCount;
        std::unordered_set<std::string> uniquePaths;
        std::vector<std::string> result;
        for (const auto& path : paths) {
            if (pathCount.find(path) == pathCount.end()) {
                pathCount[path] = 1;
            } else {
                pathCount[path]++;
            }
        }
        for (const auto& path : paths) {
            if (pathCount[path] > 1 && uniquePaths.find(path) == uniquePaths.end()) {
                result.push_back(path);
                uniquePaths.insert(path);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> paths1 = {"/a", "/a/b", "/a/b/c", "/a/b/c/d", "/m", "/m/n", "/m/n/o"};
    std::vector<std::string> result1 = solution.deleteDuplicateFolder(paths1);
    for (const auto& path : result1) {
        std::cout << path << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> paths2 = {"/", "/a", "/a/b", "/a/b/c", "/d", "/d/e", "/d/e/f"};
    std::vector<std::string> result2 = solution.deleteDuplicateFolder(paths2);
    for (const auto& path : result2) {
        std::cout << path << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> paths3 = {"/a", "/a/b", "/a/b/c", "/a/b/c/d", "/x", "/x/y", "/x/y/z"};
    std::vector<std::string> result3 = solution.deleteDuplicateFolder(paths3);
    for (const auto& path : result3) {
        std::cout << path << " ";
    }
    std::cout << std::endl;

    return 0;
}
```