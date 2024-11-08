/*
34. Find First and Last Position of Element in Sorted Array
Solved
Medium
Topics
Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
 */
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        int border_left = -1;
        int border_right = -1;
        int index = -1;

        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                index = mid;
                break;
            }
        }

        if (index == -1) {
            return {border_left, border_right};
        }
        // std::cout << "index: " << index << '\n';

        int count_left = index;
        int count_right = index;

        while (true) {
            if (nums[count_left] == target) {
                border_left = count_left;
                if (count_left > 0) {
                    count_left--;
                } else if (count_left == 0) {
                    break;
                }
            } else if (nums[count_left] != target) {
                break;
            }
        }
        // std::cout << "border_left: " << border_left << '\n';

        while (true) {
            if (nums[count_right] == target) {
                border_right = count_right;
                if (count_right < right) {
                    count_right++;
                } else if (count_right == right) {
                    break;
                }
            } else if (nums[count_right] != target) {
                break;
            }
        }
        // std::cout << "border_right: " << border_right << '\n';

        return {border_left, border_right};
    }
};

int main(){
    Solution sol;
    std::vector<int> vec{5,7,7,8,8,10};
    auto a = sol.searchRange(vec,8);
    std::cout << "answer: [" << a[0] << ", " << a[1] << "]" << '\n';
    return 0;
}