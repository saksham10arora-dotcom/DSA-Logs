```cpp
// LeetCode Problem: Course Schedule
// https://leetcode.com/problems/course-schedule/
// Given the number of courses and a list of prerequisite pairs, return whether it is possible to finish all courses.

// Brute Force Approach: O(2^n * n) - trying all possible course orders
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<bool> visited(numCourses, false);
//         for (int i = 0; i < numCourses; i++) {
//             if (!dfs(i, visited, prerequisites)) return false;
//         }
//         return true;
//     }
// private:
//     bool dfs(int course, vector<bool>& visited, vector<vector<int>>& prerequisites) {
//         if (visited[course]) return false;
//         visited[course] = true;
//         for (auto& pair : prerequisites) {
//             if (pair[0] == course) {
//                 if (!dfs(pair[1], visited, prerequisites)) return false;
//             }
//         }
//         visited[course] = false;
//         return true;
//     }
// };

// Optimal Solution: O(n + m) - using topological sorting with DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        for (auto& pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, graph, visited)) return false;
        }
        return true;
    }
private:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[course] == 1) return false; // cycle detected
        if (visited[course] == 2) return true; // already visited
        visited[course] = 1;
        for (int neighbor : graph[course]) {
            if (!dfs(neighbor, graph, visited)) return false;
        }
        visited[course] = 2;
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> test1 = {{1,0}};
    cout << boolalpha << solution.canFinish(2, test1) << endl; // true
    vector<vector<int>> test2 = {{1,0},{0,1}};
    cout << boolalpha << solution.canFinish(2, test2) << endl; // false
    vector<vector<int>> test3 = {{1,0},{2,0},{3,1},{3,2}};
    cout << boolalpha << solution.canFinish(4, test3) << endl; // true
    return 0;
}
```