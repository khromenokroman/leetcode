/*
 1572. Matrix Diagonal Sum
Easy
Topics
Companies
Hint
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are
not part of the primary diagonal.



Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5


Constraints:

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

class Solution {
   public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        int sum = 0;
        int max_size = mat.size() - 1;
        for (auto i = 0; i < mat.size(); i++) {
            sum += mat[i][i];
            if (i != (max_size - i)) {
                sum += mat[i][max_size - i];
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    //    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //    std::vector<std::vector<int>> mat = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    std::vector<std::vector<int>> mat = {{5}};
    std::cout << "Maximum wealth: " << sol.diagonalSum(mat) << std::endl;
    return 0;
}