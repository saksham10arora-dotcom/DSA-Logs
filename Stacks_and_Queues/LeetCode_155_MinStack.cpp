```cpp
// LeetCode problem 155: Min Stack, https://leetcode.com/problems/min-stack/
// Design a stack that supports push, pop, top and retrieving the minimum element in constant time.

// Brute force approach: Use a single stack and scan the stack to find the minimum element each time, O(n) for min() operation
// class MinStack {
//     private:
//         stack<int> s;
//     public:
//         void push(int x) { s.push(x); }
//         void pop() { s.pop(); }
//         int top() { return s.top(); }
//         int getMin() {
//             int minVal = INT_MAX;
//             stack<int> temp = s;
//             while (!temp.empty()) {
//                 minVal = min(minVal, temp.top());
//                 temp.pop();
//             }
//             return minVal;
//         }
// };

// Optimal solution: Use two stacks, one for storing the actual elements and another for storing the minimum elements, O(1) for all operations
class MinStack {
private:
    stack<int> s;
    stack<int> minS;
public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }
    void pop() {
        if (!s.empty()) {
            if (s.top() == minS.top()) {
                minS.pop();
            }
            s.pop();
        }
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return minS.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl;  // Output: -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;     // Output: 0
    std::cout << minStack.getMin() << std::endl;  // Output: -2

    MinStack minStack2;
    minStack2.push(1);
    std::cout << minStack2.getMin() << std::endl;  // Output: 1
    minStack2.push(2);
    std::cout << minStack2.getMin() << std::endl;  // Output: 1
    minStack2.pop();
    std::cout << minStack2.getMin() << std::endl;  // Output: 1

    MinStack minStack3;
    minStack3.push(10);
    minStack3.push(20);
    minStack3.push(30);
    std::cout << minStack3.getMin() << std::endl;  // Output: 10
    minStack3.pop();
    std::cout << minStack3.getMin() << std::endl;  // Output: 10
    minStack3.pop();
    std::cout << minStack3.getMin() << std::endl;  // Output: 10

    return 0;
}
```