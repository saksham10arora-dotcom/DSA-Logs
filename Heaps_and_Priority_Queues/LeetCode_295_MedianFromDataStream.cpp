/**
 * Problem: Find Median from Data Stream (LeetCode 295)
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// --- Optimal Solution (Two Heaps) ---
// Time Complexity: O(log N) per add, O(1) per find
// Space Complexity: O(N)
class MedianFinder {
    priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // 2.0
    return 0;
}















