/**
 * Problem: Min Cost to Connect All Points (LeetCode 1584)
 * Link: https://leetcode.com/problems/min-cost-to-connect-all-points/
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Prim's Algorithm) ---
// Time Complexity: O(E log V) = O(N^2 log N)
// Space Complexity: O(V^2)
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    int cost = 0, edges = 0;
    while (edges < n) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;
        cost += d;
        edges++;
        
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                pq.push({dist, v});
            }
        }
    }
    return cost;
}

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Min Cost: " << minCostConnectPoints(points) << endl;
    return 0;
}






















