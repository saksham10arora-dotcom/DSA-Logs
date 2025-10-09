```cpp
// Codeforces_768C_ReorganizeString, https://codeforces.com/contest/768/problem/C, Reorganize the string such that no two adjacent characters are the same.

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

// Brute force approach: try all possible permutations of the string and check if any of them satisfy the condition (O(n!))
// std::string reorganizeStringBruteForce(std::string s) {
//     // implementation
// }

// Optimal solution: use a max heap to store the frequency of each character and construct the result string (O(n log k))
std::string reorganizeString(std::string s) {
    std::unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    std::priority_queue<std::pair<int, char>> maxHeap;
    for (auto& pair : freq) {
        maxHeap.push({pair.second, pair.first});
    }

    std::string result;
    while (!maxHeap.empty()) {
        auto pair1 = maxHeap.top();
        maxHeap.pop();
        if (!result.empty() && result.back() == pair1.second) {
            if (maxHeap.empty()) {
                return "";
            }
            auto pair2 = maxHeap.top();
            maxHeap.pop();
            result += pair2.second;
            if (--pair2.first > 0) {
                maxHeap.push(pair2);
            }
            maxHeap.push(pair1);
        } else {
            result += pair1.second;
            if (--pair1.first > 0) {
                maxHeap.push(pair1);
            }
        }
    }
    return result;
}

int main() {
    std::cout << reorganizeString("aaab") << std::endl;  // Output: "abaa"
    std::cout << reorganizeString("aaabb") << std::endl;  // Output: "ababa"
    std::cout << reorganizeString("aaaabb") << std::endl;  // Output: ""
    return 0;
}
```