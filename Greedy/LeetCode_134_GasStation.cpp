/**
 * Problem: Gas Station (LeetCode 134)
 * Link: https://leetcode.com/problems/gas-station/
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// --- Optimal Solution (Greedy One Pass) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
        return -1;
    }
    int total = 0;
    int res = 0;
    for (int i = 0; i < gas.size(); i++) {
        total += (gas[i] - cost[i]);
        if (total < 0) {
            total = 0;
            res = i + 1;
        }
    }
    return res;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << "Start Index: " << canCompleteCircuit(gas, cost) << endl;
    return 0;
}













