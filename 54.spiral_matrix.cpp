/*
54. Spiral Matrix
Medium
Topics
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
 */
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> m_vec{};
    int m_max_elements = 0;
    int m_x = 0;
    int m_y = 0;
    int m_max_x = 0;
    int m_max_y = 0;
    void right_and_down(std::vector<std::vector<int>> const& matrix) {
        for (auto i = m_x; i <= m_max_x; i++) {
            m_vec.emplace_back(matrix[m_y][i]);
            m_max_elements--;
        }
        m_y++;
        for (auto i = m_y; i <= m_max_y; i++) {
            m_vec.emplace_back(matrix[i][m_max_x]);
            m_max_elements--;
        }
        m_max_x--;
    }
    void left_and_up(std::vector<std::vector<int>> const& matrix) {
        for (auto i = m_max_x; i >= m_x; i--) {
            m_vec.emplace_back(matrix[m_max_y][i]);
            m_max_elements--;
        }
        m_max_y--;
        for (auto i = m_max_y; i >= m_y; i--) {
            m_vec.emplace_back(matrix[i][m_x]);
            m_max_elements--;
        }
        m_x++;
    }
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        m_vec.reserve(matrix.size() * matrix[0].size());
        m_max_x = static_cast<int>(matrix[0].size() - 1);
        m_max_y = static_cast<int>(matrix.size() - 1);
        m_max_elements = (m_max_x + 1) * (m_max_y + 1);
        while (true) {
            right_and_down(matrix);
            if (!m_max_elements) {
                break;
            }
            left_and_up(matrix);
            if (!m_max_elements) {
                break;
            }
        }
        return std::move(m_vec);
    }
};

int main() {
    Solution sol;
    //    std::vector<std::vector<int>> vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> vec{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    //    std::vector<std::vector<int>> vec{{2, 5, 8}, {4, 0, -1}};
    auto a = sol.spiralOrder(vec);
    for (auto i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}