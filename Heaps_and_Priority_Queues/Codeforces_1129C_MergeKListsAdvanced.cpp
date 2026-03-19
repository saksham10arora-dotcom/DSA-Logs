```cpp
// Codeforces_1129C_MergeKListsAdvanced
// https://codeforces.com/contest/1129/problem/C
// Merge k sorted lists into one sorted list.

#include <iostream>
#include <queue>
#include <vector>

// Brute force approach: O(n*k*log(n*k)) complexity
// std::vector<int> mergeKLists(std::vector<std::vector<int>>& lists) {
//     std::vector<int> result;
//     for (const auto& list : lists) {
//         result.insert(result.end(), list.begin(), list.end());
//     }
//     std::sort(result.begin(), result.end());
//     return result;
// }

// Optimal solution: O(n*k*log(k)) complexity
std::vector<int> mergeKLists(std::vector<std::vector<int>>& lists) {
    std::vector<int> result;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            pq.push({lists[i][0], i});
        }
    }
    while (!pq.empty()) {
        int val = pq.top().first;
        int listIndex = pq.top().second;
        pq.pop();
        result.push_back(val);
        if (listIndex + 1 < lists.size() &&!lists[listIndex].empty()) {
            lists[listIndex].erase(lists[listIndex].begin());
            if (!lists[listIndex].empty()) {
                pq.push({lists[listIndex][0], listIndex});
            }
        }
    }
    return result;
}

int main() {
    // Test case 1:
    std::vector<std::vector<int>> lists1 = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    std::vector<int> result1 = mergeKLists(lists1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 2:
    std::vector<std::vector<int>> lists2 = {{}, {1, 2, 3}, {}};
    std::vector<int> result2 = mergeKLists(lists2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 3:
    std::vector<std::vector<int>> lists3 = {{1}, {2}, {3}};
    std::vector<int> result3 = mergeKLists(lists3);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```