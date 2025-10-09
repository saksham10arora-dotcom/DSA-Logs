```cpp
// Image Smoother, https://leetcode.com/problems/image-smoother/, Given a 2D image, perform an image smoothing operation on every pixel of the image using the box filter, i.e., replacing every pixel by the average value of the neighboring pixels.

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& M) {
        int rows = M.size();
        int cols = M[0].size();
        std::vector<std::vector<int>> result(rows, std::vector<int>(cols));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = 0;
                int count = 0;
                for (int x = std::max(0, i - 1); x <= std::min(rows - 1, i + 1); x++) {
                    for (int y = std::max(0, j - 1); y <= std::min(cols - 1, j + 1); y++) {
                        sum += M[x][y];
                        count++;
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }
};

// Brute force approach with O(rows * cols * 9) complexity
// Optimal solution with O(rows * cols) complexity

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<std::vector<int>> M1 = {{1,1,1},{1,0,1},{1,1,1}};
    std::vector<std::vector<int>> result1 = solution.imageSmoother(M1);
    for (const auto& row : result1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    // Test case 2
    std::vector<std::vector<int>> M2 = {{100,200,100},{200,50,200},{100,200,100}};
    std::vector<std::vector<int>> result2 = solution.imageSmoother(M2);
    for (const auto& row : result2) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
```