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
    static int check_zero(size_t index, std::vector<int> const& vec) {
        for (auto i = index; i < vec.size(); i++) {
            if (vec[i] != 0) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
    void moveZeroes(std::vector<int>& nums) {
        auto size_vec = nums.size();
        for (auto i = 0; i < size_vec; i++) {
            if (nums[i] == 0) {
                if (i + 1 < size_vec) {
                    int index = 0;
                    if (nums[i + 1] == 0) {
                        index = check_zero(i, nums);
                        if (index == -1) {
                            break;
                        }
                        std::swap(nums[i], nums[index]);
                        index = 0;
                    } else {
                        std::swap(nums[i], nums[i + 1]);
                    }
                }
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