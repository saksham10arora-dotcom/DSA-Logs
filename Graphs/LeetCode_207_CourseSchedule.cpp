/**
 * Problem: Course Schedule (LeetCode 207)
 * Link: https://leetcode.com/problems/course-schedule/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// --- Optimal Solution (Kahn's Algorithm - BFS) ---
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& edge : prerequisites) {
        adj[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return count == numCourses;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << (canFinish(numCourses, prerequisites) ? "Possible" : "Impossible") << endl;
    return 0;
}






















