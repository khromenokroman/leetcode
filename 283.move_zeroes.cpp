/*
 283. Move Zeroes
Easy
Topics
Companies
Hint
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero
elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Follow up: Could you minimize the total number of operations done?
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

class Solution {
   public:
    void moveZeroes(std::vector<int>& nums) {
        int head = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[head++], nums[i]);
            }
        }
    }
};

int main() {
    Solution sol;
    //        std::vector<int> vec{0, 1, 2, 3};
    //        std::vector<int> vec{0, 1, 2, 3, 0};
    std::vector<int> vec{0, 1, 0, 2, 3, 0};
    //    std::vector<int> vec{0};
    sol.moveZeroes(vec);

    std::ranges::for_each(vec, [](auto const& item) { std::cout << item << "\t"; });
    std::cout << std::endl;
}