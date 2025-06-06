```cpp
// Median From Data Stream, https://leetcode.com/problems/median-from-data-stream/
// Median is the middle value in an ordered integer list. If the size of the list is even, 
// there is no middle value.  So the median is the mean of the two middle number.

// Brute force approach: O(n log n) for sorting
// class MedianFinder {
//     vector<int> nums;
// public:
//     MedianFinder() {}
//     void addNum(int num) {
//         nums.push_back(num);
//     }
//     double findMedian() {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         if (n % 2 == 0) {
//             return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
//         } else {
//             return nums[n / 2];
//         }
//     }
// };

// Optimal solution: O(log n) for heap operations
class MedianFinder {
    priority_queue<int> maxHeap; // max heap for smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap for larger half
public:
    MedianFinder() {}
    void addNum(int num) {
        // Add to max heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // Balance heaps
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
    printf("%.1f\n", mf.findMedian()); // 1.5
    mf.addNum(3);
    printf("%.1f\n", mf.findMedian()); // 2.0

    MedianFinder mf2;
    mf2.addNum(-1);
    mf2.addNum(-2);
    mf2.addNum(-3);
    mf2.addNum(-4);
    mf2.addNum(-5);
    printf("%.1f\n", mf2.findMedian()); // -3.0

    return 0;
}
```