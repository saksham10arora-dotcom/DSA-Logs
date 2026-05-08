```cpp
// LeetCode problem 295: Find Median From Data Stream, https://leetcode.com/problems/find-median-from-data-stream/
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
// In this case, the median is the mean of the two middle values, which is (list[listSize / 2 - 1] + list[listSize / 2]) / 2.

// Brute force approach: sorting the data stream after each insertion, O(n log n) for sorting, O(n) for insertion, O(n) for finding median
// class MedianFinder {
// public:
//     vector<int> data;
//     MedianFinder() {}
//     void addNum(int num) {
//         data.push_back(num);
//         sort(data.begin(), data.end());
//     }
//     double findMedian() {
//         int n = data.size();
//         if (n % 2 == 0) {
//             return (data[n / 2 - 1] + data[n / 2]) / 2.0;
//         } else {
//             return data[n / 2];
//         }
//     }
// };

// Optimal solution: using two heaps, max heap for the smaller half and min heap for the larger half, O(log n) for insertion and finding median
class MedianFinder {
public:
    priority_queue<int> maxHeap; // max heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap for the larger half
    MedianFinder() {}
    void addNum(int num) {
        // add num to the correct heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2
    mf.addNum(4);
    cout << mf.findMedian() << endl; // 2.5
    return 0;
}
```