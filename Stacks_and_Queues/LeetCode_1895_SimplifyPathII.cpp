```cpp
// LeetCode problem 1895: Simplify Path II
// https://leetcode.com/problems/simplify-path-ii/
// Given a string path, which is an absolute path (starting with a leading slash '/') that starts at the root directory of a file system, 
// you need to simplify it by removing any redundant '/' and making it the shortest possible absolute path.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Brute force approach with O(n^2) complexity
// std::string simplifyPathBruteForce(const std::string& path) {
//     std::vector<std::string> components;
//     std::stringstream ss(path);
//     std::string component;
//     while (std::getline(ss, component, '/')) {
//         if (component == "..") {
//             if (!components.empty()) {
//                 components.pop_back();
//             }
//         } else if (component != "" && component != ".") {
//             components.push_back(component);
//         }
//     }
//     std::string simplifiedPath;
//     for (const auto& c : components) {
//         simplifiedPath += "/" + c;
//     }
//     return simplifiedPath;
// }

// Optimal solution with O(n) complexity
std::string simplifyPath(const std::string& path) {
    std::vector<std::string> stack;
    std::stringstream ss(path);
    std::string component;
    while (std::getline(ss, component, '/')) {
        if (component == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else if (component != "" && component != ".") {
            stack.push_back(component);
        }
    }
    std::string simplifiedPath;
    for (const auto& c : stack) {
        simplifiedPath += "/" + c;
    }
    return simplifiedPath.empty() ? "/" : simplifiedPath;
}

int main() {
    std::cout << simplifyPath("/home/") << std::endl;  // Output: "/home"
    std::cout << simplifyPath("/../") << std::endl;  // Output: "/"
    std::cout << simplifyPath("/home//foo/") << std::endl;  // Output: "/home/foo"
    return 0;
}
```