/*
 1351. Count Negative Numbers in a Sorted Matrix
Solved
Easy
Topics
Companies
Hint
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of
negative numbers in grid.



Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100


Follow up: Could you find an O(n + m) solution?
 */
#include <iostream>
#include <vector>
class Solution {
   public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int count_negative = 0;
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] < 0) {
                    count_negative++;
                }
            }
        }
        return count_negative;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> vec{{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    std::cout << sol.countNegatives(vec) << std::endl;
    return 0;
}