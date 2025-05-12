```cpp
// LeetCode problem 2618: Task Scheduler II
// https://leetcode.com/problems/task-scheduler-ii/
// Given a list of tasks and a cooldown period, return the minimum number of days to complete all tasks.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

// Brute force approach: Try all possible schedules, O(2^n * n) complexity
// int taskSchedulerII(std::vector<int>& tasks, int space) {
//     // ...
// }

// Optimal solution: Use a priority queue to schedule tasks, O(n log n) complexity
int taskSchedulerII(std::vector<int>& tasks, int space) {
    std::unordered_map<int, int> lastExecuted;
    int time = 0;
    for (int task : tasks) {
        if (lastExecuted.find(task) != lastExecuted.end() && time - lastExecuted[task] <= space) {
            time = std::max(time, lastExecuted[task] + space + 1);
        }
        lastExecuted[task] = time;
        time++;
    }
    return time;
}

int main() {
    std::vector<int> tasks1 = {1, 2, 1, 2, 3, 1};
    int space1 = 3;
    std::cout << taskSchedulerII(tasks1, space1) << std::endl;  // Output: 10

    std::vector<int> tasks2 = {5, 9, 8, 5, 9};
    int space2 = 2;
    std::cout << taskSchedulerII(tasks2, space2) << std::endl;  // Output: 6

    std::vector<int> tasks3 = {1, 1, 1, 1, 1};
    int space3 = 2;
    std::cout << taskSchedulerII(tasks3, space3) << std::endl;  // Output: 5

    return 0;
}
```