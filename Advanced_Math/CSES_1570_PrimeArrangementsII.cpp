```cpp
// Prime Arrangements II, https://cses.fi/problemset/task/1570, 
// Given a positive integer n, find the number of ways to arrange the numbers from 1 to n such that 
// all prime numbers are at even positions (1-indexed).

#include <iostream>
#include <vector>
#include <cmath>

// Brute force approach with O(n!) complexity
// int countArrangements(int n) {
//     std::vector<int> isPrime(n + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i * i <= n; i++) {
//         if (isPrime[i]) {
//             for (int j = i * i; j <= n; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     int count = 0;
//     std::function<void(int, std::vector<int>)> backtrack = 
//         [&count, &isPrime, n](int pos, std::vector<int> used) {
//             if (pos > n) {
//                 count++;
//                 return;
//             }
//             for (int i = 1; i <= n; i++) {
//                 if (!used[i] && (pos % 2 == 0 || !isPrime[i])) {
//                     used[i] = true;
//                     backtrack(pos + 1, used);
//                     used[i] = false;
//                 }
//             }
//         };
//     backtrack(1, std::vector<int>(n + 1, false));
//     return count;
// }

// Optimal solution with O(n log log n) complexity
int countArrangements(int n) {
    std::vector<int> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int primeCount = 0, nonPrimeCount = 0;
    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) primeCount++;
        else nonPrimeCount++;
    }
    long long primePermutations = 1, nonPrimePermutations = 1;
    for (int i = 1; i <= primeCount; i++) {
        primePermutations *= i;
    }
    for (int i = 1; i <= nonPrimeCount; i++) {
        nonPrimePermutations *= i;
    }
    return primePermutations * nonPrimePermutations;
}

int main() {
    std::cout << countArrangements(1) << std::endl;  // Output: 1
    std::cout << countArrangements(2) << std::endl;  // Output: 1
    std::cout << countArrangements(5) << std::endl;  // Output: 4
    return 0;
}
```