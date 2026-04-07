```cpp
// Kth Largest Stream, https://cses.fi/problemset/task/1984
// Given a stream of integers and an integer k, find the kth largest element in the stream.

#include <iostream>
#include <queue>
#include <vector>

// Brute force approach: sorting the entire stream after each insertion (O(n^2 log n))
std::vector<int> bruteForce(std::vector<int>& stream, int k) {
    std::vector<int> result;
    for (int i = 0; i < stream.size(); i++) {
        std::vector<int> sortedStream(stream.begin(), stream.begin() + i + 1);
        std::sort(sortedStream.rbegin(), sortedStream.rend());
        result.push_back(sortedStream[k - 1]);
    }
    return result;
}

// Optimal solution: using a min-heap to keep track of the k largest elements (O(n log k))
std::vector<int> optimalSolution(std::vector<int>& stream, int k) {
    std::vector<int> result;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int num : stream) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else if (num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
        if (minHeap.size() == k) {
            result.push_back(minHeap.top());
        }
    }
    return result;
}

int main() {
    std::vector<int> stream1 = {3, 2, 1, 4};
    int k1 = 2;
    std::vector<int> result1 = optimalSolution(stream1, k1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> stream2 = {5, 3, 1, 4, 2};
    int k2 = 3;
    std::vector<int> result2 = optimalSolution(stream2, k2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> stream3 = {1, 2, 3, 4, 5};
    int k3 = 1;
    std::vector<int> result3 = optimalSolution(stream3, k3);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```