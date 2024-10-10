/*
 896. Monotonic Array
Easy
Topics
Companies
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for
all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.



Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false


Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 128 8.72  99.17 84.68
class Solution {
   public:
    bool isMonotonic(std::vector<int>& nums) {
        bool status_up{true};
        bool status_down{true};

        std::ranges::for_each(std::views::iota(0) | std::views::take(nums.size()), [&nums, &status_up,&status_down](auto const& i)  {
            if (i != nums.size() - 1) {
                if (nums[i] <= nums[i + 1]) {
                } else {
                    status_up = false;
                }
            }
            if (i != nums.size() - 1) {
                if (nums[i] >= nums[i + 1]) {
                } else {
                    status_down = false;
                }
            }
        });

        return status_up or status_down;
    }
};

int main() {
    //    std::vector<int> vec{1, 2, 2, 3};
    //        std::vector<int> vec{6, 5, 4, 4};
    std::vector<int> vec{1, 3, 2};
    Solution sol;
    std::cout << sol.isMonotonic(vec) << std::endl;
    return 0;
}