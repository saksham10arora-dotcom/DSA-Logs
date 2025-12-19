```cpp
// Shopping Offers, https://leetcode.com/problems/shopping-offers/
// In this problem, we are given a list of items and their prices, and a list of shopping offers.
// Each offer is a list of items and a total price. We need to find the minimum cost to buy all items.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    // Brute force approach with O(2^n) complexity
    int shoppingOffersBruteForce(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = INT_MAX;
        for (int mask = 0; mask < (1 << special.size()); mask++) {
            vector<int> tmp = needs;
            int cost = 0;
            for (int i = 0; i < special.size(); i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < price.size(); j++) {
                        tmp[j] -= special[i][j];
                        if (tmp[j] < 0) break;
                    }
                    if (tmp[0] < 0) break;
                    cost += special[i].back();
                }
            }
            if (tmp[0] < 0) continue;
            for (int i = 0; i < price.size(); i++) {
                cost += tmp[i] * price[i];
            }
            res = min(res, cost);
        }
        return res;
    }

    // Optimal solution with O(n * m * k) complexity, where n is the number of items, m is the number of offers, and k is the maximum number of items in an offer
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return dfs(price, special, needs, memo);
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        string key;
        for (int need : needs) key += to_string(need) + ",";
        if (memo.count(key)) return memo[key];
        int res = 0;
        for (int i = 0; i < price.size(); i++) {
            res += needs[i] * price[i];
        }
        for (vector<int>& offer : special) {
            vector<int> tmp = needs;
            bool valid = true;
            for (int i = 0; i < price.size(); i++) {
                tmp[i] -= offer[i];
                if (tmp[i] < 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = min(res, offer.back() + dfs(price, special, tmp, memo));
            }
        }
        memo[key] = res;
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> price = {2, 5};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};
    cout << solution.shoppingOffers(price, special, needs) << endl;  // Output: 14

    price = {0, 0, 0};
    special = {{1, 1, 0, -2}, {2, 2, 1, -5}, {3, 0, 1, -4}};
    needs = {2, 2, 1};
    cout << solution.shoppingOffers(price, special, needs) << endl;  // Output: -5

    price = {1, 1, 1};
    special = {{1, 1, 1, 0}};
    needs = {2, 2, 2};
    cout << solution.shoppingOffers(price, special, needs) << endl;  // Output: 0

    return 0;
}
```