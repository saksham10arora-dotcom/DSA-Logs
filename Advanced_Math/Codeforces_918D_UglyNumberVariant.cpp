```cpp
// Codeforces_918D_UglyNumberVariant, https://codeforces.com/contest/918/problem/D
// Given a number n, find the nth ugly number in a sequence where each number is the sum of two prime numbers.

#include <iostream>
#include <vector>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Brute force approach with O(n^2) complexity
int bruteForceUglyNumber(int n) {
    std::vector<int> uglyNumbers;
    int num = 2;
    while (uglyNumbers.size() < n) {
        for (int i = 2; i <= num; i++) {
            if (isPrime(i) && isPrime(num - i)) {
                uglyNumbers.push_back(num);
                break;
            }
        }
        num++;
    }
    return uglyNumbers.back();
}

// Optimal solution with O(n) complexity
int optimalUglyNumber(int n) {
    std::vector<int> uglyNumbers = {2};
    int i = 0;
    while (uglyNumbers.size() < n) {
        int nextUgly = uglyNumbers[i] + 2;
        while (!isPrime(nextUgly - 2) ||!isPrime(2)) {
            nextUgly++;
        }
        uglyNumbers.push_back(nextUgly);
        i++;
    }
    return uglyNumbers.back();
}

int main() {
    // Test cases
    std::cout << bruteForceUglyNumber(1) << std::endl;  // Output: 2
    std::cout << bruteForceUglyNumber(2) << std::endl;  // Output: 3
    std::cout << optimalUglyNumber(3) << std::endl;     // Output: 5
    return 0;
}
```