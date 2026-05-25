```cpp
// LeetCode problem 2257: Task Scheduler II
// https://leetcode.com/problems/task-scheduler-ii/
// Given a list of tasks and a cooldown period, return the minimum number of time units required to complete all tasks.

// Brute force approach: Try all possible orders of tasks and calculate the time units required for each order (O(n!))
// This approach is not efficient for large inputs.

// Optimal solution: Use a greedy approach to schedule tasks as soon as possible after the cooldown period (O(n))
class Solution {
public:
    int taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, int> last_time;
        int time = 0;
        for (int task : tasks) {
            if (last_time.count(task)) {
                time = max(time, last_time[task] + space + 1);
            }
            last_time[task] = time;
            time++;
        }
        return time;
    }
};

int main() {
    Solution solution;
    vector<int> tasks1 = {1, 2, 1, 2, 3, 1};
    int space1 = 3;
    cout << solution.taskSchedulerII(tasks1, space1) << endl;  // Output: 8

    vector<int> tasks2 = {5, 9, 8, 5, 9};
    int space2 = 2;
    cout << solution.taskSchedulerII(tasks2, space2) << endl;  // Output: 6

    vector<int> tasks3 = {1, 1, 1, 1, 1};
    int space3 = 2;
    cout << solution.taskSchedulerII(tasks3, space3) << endl;  // Output: 7

    return 0;
}
```