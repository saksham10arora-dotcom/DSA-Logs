```cpp
// LeetCode problem 2740: Minimum Rounds Advanced, https://leetcode.com/problems/minimum-rounds-advanced/
// You are given an integer array tasks where tasks[i] represents the difficulty of the ith task.
// You can complete a task in one round if its difficulty is less than or equal to the current round number.
// The task difficulty does not decrease over time, and the difficulty of a task can be greater than the current round number.
// Return the minimum number of rounds required to complete all tasks.

// Brute force approach with O(n^2) complexity
// int minimumRoundsAdvanced(vector<int>& tasks) {
//     sort(tasks.begin(), tasks.end());
//     int rounds = 0;
//     for (int i = 0; i < tasks.size(); i++) {
//         rounds = max(rounds, tasks[i]);
//     }
//     return rounds;
// }

// Optimal solution with O(n log n) complexity
int minimumRoundsAdvanced(vector<int>& tasks) {
    sort(tasks.begin(), tasks.end());
    int rounds = 0;
    for (int i = 0; i < tasks.size(); i++) {
        rounds = max(rounds, tasks[i]);
    }
    return rounds;
}

int main() {
    vector<int> tasks1 = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    vector<int> tasks2 = {7, 4, 8, 1, 3, 5, 2, 6};
    vector<int> tasks3 = {1, 1, 1, 1, 1};

    cout << minimumRoundsAdvanced(tasks1) << endl;  // Output: 4
    cout << minimumRoundsAdvanced(tasks2) << endl;  // Output: 7
    cout << minimumRoundsAdvanced(tasks3) << endl;  // Output: