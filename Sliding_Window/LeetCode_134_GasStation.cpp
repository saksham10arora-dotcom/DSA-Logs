```cpp
// LeetCode problem 134: Gas Station, https://leetcode.com/problems/gas-station/
// Given two arrays, gas and cost, representing the amount of gas and cost of gas at each station,
// determine if it is possible to complete a circuit.

// Brute force approach: O(n^2) complexity
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int tank = 0;
            bool possible = true;
            for (int j = i; j < i + n; j++) {
                tank += gas[j % n] - cost[j % n];
                if (tank < 0) {
                    possible = false;
                    break;
                }
            }
            if (possible) return i;
        }
        return -1;
    }
};

// Optimal solution: O(n) complexity
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0, tank = 0, start = 0;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return totalGas < totalCost ? -1 : start;
    }
};

int main() {
    Solution solution;
    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    cout << solution.canCompleteCircuit(gas1, cost1) << endl;  // Output: 3

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    cout << solution.canCompleteCircuit(gas2, cost2) << endl;  // Output: -1

    vector<int> gas3 = {5,1,2,3,4};
    vector<int> cost3 = {4,4,1,5,1};
    cout << solution.canCompleteCircuit(gas3, cost3) << endl;  // Output: 4

    return 0;
}
```