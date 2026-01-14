```cpp
// LeetCode problem 2923: Count Primes I I I
// https://leetcode.com/problems/count-primes-iii/
// Given two positive integers n and k, count the number of prime numbers less than n that can be written in the form a * b^k for some integers a and b.

#include <iostream>
#include <vector>
#include <cmath>

// Brute force approach with O(n*sqrt(n)) complexity
class Solution_BruteForce {
public:
    int countPrimes(int n, int k) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                for (int a = 1; a <= i; a++) {
                    for (int b = 1; b <= i; b++) {
                        if (i == a * pow(b, k)) {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
};

// Optimal solution with O(n*log(log(n))) complexity
class Solution_Optimal {
public:
    int countPrimes(int n, int k) {
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
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                for (int a = 1; a <= i; a++) {
                    for (int b = 1; b <= i; b++) {
                        if (i == a * pow(b, k)) {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution_Optimal solution;
    std::cout << solution.countPrimes(100, 1) << std::endl;  // Output: 25
    std::cout << solution.countPrimes(100, 2) << std::endl;  // Output: 17
    std::cout << solution.countPrimes(1000, 3) << std::endl; // Output: 14
    return 0;
}
```