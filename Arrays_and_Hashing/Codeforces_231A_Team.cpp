```cpp
// Codeforces_231A_Team, https://codeforces.com/problemset/problem/231/A, 
// Determine the number of problems a team can solve given the skills of its members.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^3) complexity
// int countSolvedProblems(std::vector<int>& skills, std::vector<int>& problems) {
//     int count = 0;
//     for (int i = 0; i < problems.size(); i++) {
//         for (int j = 0; j < skills.size(); j++) {
//             for (int k = j + 1; k < skills.size(); k++) {
//                 if (skills[j] + skills[k] >= problems[i]) {
//                     count++;
//                     break;
//                 }
//             }
//         }
//     }
//     return count;
// }

// Optimal solution with O(n^2) complexity
int countSolvedProblems(std::vector<int>& skills, std::vector<int>& problems) {
    int count = 0;
    std::sort(skills.begin(), skills.end());
    for (int problem : problems) {
        for (int i = 0; i < skills.size() - 1; i++) {
            for (int j = i + 1; j < skills.size(); j++) {
                if (skills[i] + skills[j] >= problem) {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> skills1 = {4, 5, 2, 7};
    std::vector<int> problems1 = {3, 1, 5, 10};
    std::cout << countSolvedProblems(skills1, problems1) << std::endl;

    std::vector<int> skills2 = {1, 2, 3};
    std::vector<int> problems2 = {4, 5, 6};
    std::cout << countSolvedProblems(skills2, problems2) << std::endl;

    std::vector<int> skills3 = {10, 20, 30};
    std::vector<int> problems3 = {15, 25, 35};
    std::cout << countSolvedProblems(skills3, problems3) << std::endl;

    return 0;
}
```