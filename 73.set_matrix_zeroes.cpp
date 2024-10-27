/*
 73. Set Matrix Zeroes
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int x = -1;
        int y = -1;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (x == -1 && y == -1) {
                    if (matrix[i][j] == 0) {
                        y = i;
                        x = j;
                        break;
                    }
                }
                if (matrix[i][j] == 0) {
                    matrix[i][x] = 0;
                    matrix[y][j] = 0;
                }
            }
        }
        if (x == -1 || y == -1) {
            return;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (i != y) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    if (j != x) {
                        if (matrix[i][x] == 0) {
                            matrix[i][j] = 0;
                        }
                        if (matrix[y][j] == 0) {
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if(i==y){
                    matrix[i][j]=0;
                }
                if(j==x){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> vec{{1}};
    //        std::vector<std::vector<int>> vec{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    //        std::vector<std::vector<int>> vec{{1, 1, 1},{1,1,1}, {1, 0, 1}, {1, 1, 1}};
    //    std::vector<std::vector<int>> vec{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//    std::vector<std::vector<int>> vec{
//        {1, 1, 2, 3, 1}, {3, 0, 5, 2, 1}, {1, 3, 1, 1, 5}, {1, 3, 1, 0, 1}, {1, 3, 1, 1, 5}};
    Solution sol;
    sol.setZeroes(vec);

    for (auto const& item : vec) {
        for (auto const& row : item) {
            std::cout << row << " ";
        }
        std::cout << std::endl;
    }
}