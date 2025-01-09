/**
 * Problem: Min Stack (LeetCode 155)
 * Link: https://leetcode.com/problems/min-stack/
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Using Two Stacks or Pair) ---
// Time Complexity: O(1) for all operations
// Space Complexity: O(N)
class MinStack {
    stack<pair<int, int>> st; // {value, min_so_far}
public:
    void push(int val) {
        int current_min = st.empty() ? val : min(val, st.top().second);
        st.push({val, current_min});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << "Min: " << minStack->getMin() << endl; // -3
    minStack->pop();
    cout << "Top: " << minStack->top() << endl;    // 0
    cout << "Min: " << minStack->getMin() << endl; // -2
    return 0;
}




















