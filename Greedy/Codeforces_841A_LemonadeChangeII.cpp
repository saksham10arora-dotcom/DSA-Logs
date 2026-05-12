```cpp
// Codeforces_841A_LemonadeChangeII
// https://codeforces.com/contest/841/problem/A
// Given a number of lemons and a number of customers, determine the maximum number of customers that can be served.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: Try all possible combinations of serving customers (O(2^n))
// int maxCustomers(int lemons, std::vector<int>& customers) {
//     int maxServed = 0;
//     for (int mask = 0; mask < (1 << customers.size()); ++mask) {
//         int served = 0;
//         int remainingLemons = lemons;
//         for (int i = 0; i < customers.size(); ++i) {
//             if ((mask & (1 << i)) && remainingLemons >= customers[i]) {
//                 served++;
//                 remainingLemons -= customers[i];
//             }
//         }
//         maxServed = std::max(maxServed, served);
//     }
//     return maxServed;
// }

// Optimal solution: Sort customers by the number of lemons they need and serve them greedily (O(n log n))
int maxCustomers(int lemons, std::vector<int>& customers) {
    std::sort(customers.begin(), customers.end());
    int served = 0;
    for (int customer : customers) {
        if (lemons >= customer) {
            served++;
            lemons -= customer;
        } else {
            break;
        }
    }
    return served;
}

int main() {
    std::vector<int> test1 = {1, 2, 3};
    std::cout << maxCustomers(5, test1) << std::endl;  // Output: 2

    std::vector<int> test2 = {10, 20, 30};
    std::cout << maxCustomers(15, test2) << std::endl;  // Output: 1

    std::vector<int> test3 = {1, 1, 1, 1, 1};
    std::cout << maxCustomers(5, test3) << std::endl;  // Output: 5

    return 0;
}
```