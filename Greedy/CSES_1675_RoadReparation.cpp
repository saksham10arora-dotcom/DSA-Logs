```cpp
// Road Reparation, https://cses.fi/problemset/task/1675, 
// Given a list of road segments and their repair costs, determine the minimum cost to repair all roads.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: Try all possible combinations of road repairs (O(2^n))
// This approach is inefficient and not practical for large inputs

// Optimal solution: Sort the roads by their repair costs and repair them in order (O(n log n))
int roadReparation(std::vector<int>& roads) {
    std::sort(roads.begin(), roads.end());
    int totalCost = 0;
    for (int cost : roads) {
        totalCost += cost;
    }
    return totalCost;
}

int main() {
    // Test case 1:
    std::vector<int> roads1 = {3, 2, 1, 4};
    std::cout << roadReparation(roads1) << std::endl;  // Output: 10

    // Test case 2:
    std::vector<int> roads2 = {10, 20, 30};
    std::cout << roadReparation(roads2) << std::endl;  // Output: 60

    // Test case 3:
    std::vector<int> roads3 = {1, 1, 1, 1, 1};
    std::cout << roadReparation(roads3) << std::endl;  // Output: 5

    return 0;
}
```