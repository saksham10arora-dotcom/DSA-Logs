```cpp
// LeetCode problem 2907: Simplify Path Advanced
// https://leetcode.com/problems/simplify-path-advanced/
// Given a string path, which is an absolute path (starting with a forward slash '/') on a Unix system, 
// convert it to the simplified canonical path.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Brute force approach with O(n) complexity
class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::istringstream iss(path);
        std::string token;
        std::vector<std::string> stack;

        while (std::getline(iss, token, '/')) {
            if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (token!= "" && token!= ".") {
                stack.push_back(token);
            }
        }

        std::string result;
        for (const auto& dir : stack) {
            result += "/" + dir;
        }

        return result.empty()? "/" : result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::string path1 = "/home/";
    std::cout << solution.simplifyPath(path1) << std::endl;  // Output: "/home"

    // Test case 2
    std::string path2 = "/../";
    std::cout << solution.simplifyPath(path2) << std::endl;  // Output: "/"

    // Test case 3
    std::string path3 = "/home//foo/";
    std::cout << solution.simplifyPath(path3) << std::endl;  // Output: "/home/foo"

    return 0;
}
```