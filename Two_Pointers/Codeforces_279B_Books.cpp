```cpp
// Codeforces_279B_Books, https://codeforces.com/contest/279/problem/B
// Given a list of books with their reading times and a time limit, find the maximum number of books that can be read.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
int bruteForce(std::vector<int>& books, int timeLimit) {
    int n = books.size();
    int maxBooks = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int currentTime = 0;
        int currentBooks = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i))!= 0) {
                currentTime += books[i];
                currentBooks++;
            }
        }
        if (currentTime <= timeLimit) {
            maxBooks = std::max(maxBooks, currentBooks);
        }
    }
    return maxBooks;
}

// Optimal solution with O(n log n) complexity
int optimalSolution(std::vector<int>& books, int timeLimit) {
    std::sort(books.begin(), books.end());
    int n = books.size();
    int maxBooks = 0;
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime + books[i] <= timeLimit) {
            currentTime += books[i];
            maxBooks++;
        } else {
            break;
        }
    }
    return maxBooks;
}

int main() {
    std::vector<int> books1 = {1, 2, 3, 4, 5};
    int timeLimit1 = 10;
    std::cout << "Test case 1: " << optimalSolution(books1, timeLimit1) << std::endl;

    std::vector<int> books2 = {5, 5, 5, 5, 5};
    int timeLimit2 = 10;
    std::cout << "Test case 2: " << optimalSolution(books2, timeLimit2) << std::endl;

    std::vector<int> books3 = {1, 1, 1, 1, 1};
    int timeLimit3 = 5;
    std::cout << "Test case 3: " << optimalSolution(books3, timeLimit3) << std::endl;

    return 0;
}
```