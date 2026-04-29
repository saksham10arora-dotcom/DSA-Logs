```cpp
// LeetCode problem 2024: Count Primes Advanced
// https://leetcode.com/problems/count-primes/
// Count the number of prime numbers less than n.

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
            if (isPrime[i]) count++;
        }
        return count;
    }
};

int main() {
    Solution_Optimal solution;
    std::cout << solution.countPrimes(10) << std::endl;  // Output: 4
    std::cout << solution.countPrimes(20) << std::endl;  // Output: 8
    std::cout << solution.countPrimes(100) << std::endl; // Output: 25
    return 0;
}
```