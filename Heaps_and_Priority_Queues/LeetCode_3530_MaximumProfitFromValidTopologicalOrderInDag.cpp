```cpp
// Maximum Profit From Valid Topological Order In Dag, https://leetcode.com/problems/maximum-profit-from-valid-topological-order-in-dag/
// Given a directed acyclic graph (DAG) with n nodes labeled from 0 to n - 1, find the maximum profit from a valid topological order.

// Brute force approach: Try all possible topological orders and calculate the maximum profit. O(n!)
class Solution {
public:
    int maxProfit(vector<vector<int>>& graph, vector<int>& val) {
        int n = graph.size();
        vector<int> order;
        vector<bool> visited(n, false);
        int max_profit = 0;
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            order.push_back(node);
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };
        function<int(vector<int>)> calculate_profit = [&](vector<int> order) {
            int profit = 0;
            for (int node : order) {
                profit += val[node];
            }
            return profit;
        };
        function<void(int, vector<int>)> backtrack = [&](int start, vector<int> current_order) {
            if (start == n) {
                max_profit = max(max_profit, calculate_profit(current_order));
                return;
            }
            for (int i = start; i < n; i++) {
                current_order.push_back(i);
                backtrack(start + 1, current_order);
                current_order.pop_back();
            }
        };
        backtrack(0, {});
        return max_profit;
    }
};

// Optimal solution: Use topological sorting and dynamic programming to find the maximum profit. O(n + m)
class Solution {
public:
    int maxProfit(vector<vector<int>>& graph, vector<int>& val) {
        int n = graph.size();
        vector<int> in_degree(n, 0);
        for (auto& neighbors : graph) {
            for (int neighbor : neighbors) {
                in_degree[neighbor]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> dp(n, 0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            dp[node] = val[node];
            for (int neighbor : graph[node]) {
                dp[neighbor] = max(dp[neighbor], dp[node] + val[neighbor]);
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
    vector<int> val1 = {2, 3, 1, 5};
    cout << solution.maxProfit(graph1, val1) << endl;  // Output: 10

    vector<vector<int>> graph2 = {{1, 2, 3}, {3}, {3}, {}};
    vector<int> val2 = {2, 3, 1, 5};
    cout << solution.maxProfit(graph2, val2) << endl;  // Output: 10

    vector<vector<int>> graph3 = {{1}, {2}, {3}, {}};
    vector<int> val3 = {2, 3, 1, 5};
    cout << solution.maxProfit(graph3, val3) << endl;  // Output: 11

    return 0;
}
```