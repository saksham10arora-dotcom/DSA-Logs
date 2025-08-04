/**
 * Problem: Distinct Numbers (CSES 1621)
 * Link: https://cses.fi/problemset/task/1621
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// --- Better Solution (Sorting) ---
// Time Complexity: O(N log N)
// Space Complexity: O(1) (excluding input)
int distinctNumbersSorting(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) res++;
    }
    return res;
}

// --- Optimal Solution (Set) ---
// Time Complexity: O(N log N) 
// Space Complexity: O(N)
int distinctNumbersSet(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end());
    return st.size();
}

int main() {
    // int n; cin >> n; vector<int> a(n); for(int &x : a) cin >> x;
    // cout << distinctNumbersSorting(a) << endl;
    return 0;
}
































