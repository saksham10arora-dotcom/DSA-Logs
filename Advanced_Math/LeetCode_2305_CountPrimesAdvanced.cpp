```cpp
// LeetCode problem 2305: Count Primes Advanced
// https://leetcode.com/problems/count-primes/
// Given an integer n, return the number of prime numbers that are less than or equal to n.

#include <iostream>
#include <vector>

// Brute force approach with O(n*sqrt(n)) complexity
class Solution_BruteForce {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) count++;
        }
        return count;
    }
};

// Optimal solution with O(n*log(log(n))) complexity
class Solution_Optimal {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        std::vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (bool prime : isPrime) {
            if (prime) count++;
        }
        return count;
    }
};

int main() {
    Solution_BruteForce bruteForce;
    Solution_Optimal optimal;

    std::cout << "Brute Force Approach:" << std::endl;
    std::cout << bruteForce.countPrimes(10) << std::endl;  // Output: 4
    std::cout << bruteForce.countPrimes(20) << std::endl;  // Output: 8
    std::cout << bruteForce.countPrimes(100) << std::endl;  // Output: 25

    std::cout << "\nOptimal Solution:" << std::endl;
    std::cout << optimal.countPrimes(10) << std::endl;  // Output: 4
    std::cout << optimal.countPrimes(20) << std::endl;  // Output: 8
    std::cout << optimal.countPrimes(100) << std::endl;  // Output: 25

    return 0;
}
```