/*
66. Plus One
Easy
Topics
Companies
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the
integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer
does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.



Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].


Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>

class Solution {
   public:
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        auto size_vec = static_cast<int>(digits.size());
        for (auto i = size_vec - 1; i >= 0; i--) {
            if (i == size_vec - 1) {
                digits[i]++;
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                if (i > 0) {
                    digits[i - 1]++;
                }
                if (i == 0) {
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }

        return digits;
    }
};

int main() {
    Solution sol;
    std::vector<int> vec_digits{9, 9, 9, 9, 9};
    //    std::vector<int> vec_digits{1, 2, 3, 4, 9};
    auto print = [](auto const& item) { std::cout << item << " "; };

    std::ranges::for_each(vec_digits, print);
    std::cout << std::endl;

    auto new_vec = sol.plusOne(vec_digits);
    std::ranges::for_each(new_vec, print);
    std::cout << std::endl;
}