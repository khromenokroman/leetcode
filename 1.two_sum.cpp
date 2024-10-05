#include <iostream>
#include <map>
#include <vector>

/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

int main() {
  int target = 6;
  std::vector<int> nums = {3, 3};
  std::vector<int> nums_r;
  bool end = false;

  for (int i = 0; i < nums.size(); i++) // сравним числа и довавим в вектор
  {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {

        nums_r.push_back(i);
        nums_r.push_back(j);
        end = true;
        // return nums_r;
      }
    }
    if (end)
      break;
  }

  for (int i = 0; i < nums_r.size(); i++) // добавим элементы в масив
  {
    std::cout << nums_r[i];
  }
}