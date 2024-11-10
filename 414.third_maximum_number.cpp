/*
414. Third Maximum Number
Easy
Topics
Companies
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not
exist, return the maximum number.



Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Follow up: Can you find an O(n) solution?
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int thirdMax(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::sort(nums.begin(), nums.end(), [&nums](auto const& item1, auto const& item2) { return item1 < item2; });
        auto l = std::unique(nums.begin(), nums.end());
        nums.erase(l, nums.end());
        if (nums.size() >= 3) {
            return nums[nums.size() - 3];
        } else {
            return nums[nums.size() - 1];
        }
    }
};
int main() {
    Solution sol;
    //    std::vector<int> nums = {1, 1, 1, 2, 3, 4, 4, 5, 5, 5, 6, 2, 3};
    std::vector<int> nums = {};
    int result = sol.thirdMax(nums);
    std::cout << "max: " << result << '\n';
    for (auto const& item : nums) {
        std::cout << item << " ";
    }
    return 0;
}