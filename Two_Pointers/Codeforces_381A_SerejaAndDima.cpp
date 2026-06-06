```cpp
// Codeforces_381A_SerejaAndDima
// https://codeforces.com/contest/381/problem/A
// Sereja and Dima are playing a game with a set of cards. The set contains n cards, 
// and each card has a number written on it. The cards are divided between Sereja and Dima.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
// This approach is not efficient for large inputs
void bruteForceSolution(std::vector<int>& cards) {
    int n = cards.size();
    int serejaScore = 0;
    int dimaScore = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            serejaScore += cards[i];
        } else {
            dimaScore += cards[i];
        }
    }
    std::cout << serejaScore << " " << dimaScore << std::endl;
}

// Optimal solution with O(n) complexity
// This approach uses two pointers to keep track of the current card index
void optimalSolution(std::vector<int>& cards) {
    int n = cards.size();
    int serejaScore = 0;
    int dimaScore = 0;
    int left = 0;
    int right = n - 1;
    bool isSerejaTurn = true;
    while (left <= right) {
        if (isSerejaTurn) {
            if (cards[left] > cards[right]) {
                serejaScore += cards[left];
                left++;
            } else {
                serejaScore += cards[right];
                right--;
            }
        } else {
            if (cards[left] > cards[right]) {
                dimaScore += cards[right];
                right--;
            } else {
                dimaScore += cards[left];
                left++;
            }
        }
        isSerejaTurn = !isSerejaTurn;
    }
    std::cout << serejaScore << " " << dimaScore << std::endl;
}

int main() {
    std::vector<int> cards1 = {1, 3, 5, 7, 9};
    std::vector<int> cards2 = {2, 4, 6, 8, 10};
    std::vector<int> cards3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << "Test case 1:" << std::endl;
    optimalSolution(cards1);
    std::cout << "Test case 2:" << std::endl;
    optimalSolution(cards2);
    std::cout << "Test case 3:" << std::endl;
    optimalSolution(cards3);

    return 0;
}
```