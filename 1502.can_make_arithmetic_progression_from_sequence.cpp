/*
 1502. Can Make Arithmetic Progression From Sequence
Easy
Topics
Companies
Hint
A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the
same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise,
return false.



Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each
consecutive elements. Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


Constraints:

2 <= arr.length <= 1000
-106 <= arr[i] <= 106
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

class Solution {
   public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        if (arr.size() < 3) {
            return true;
        }
        std::ranges::sort(arr);
        auto diff = std::abs(arr[0] - arr[1]);
        for (auto i = 1; i < arr.size(); i++) {
            if (i != arr.size() - 1) {
                if (std::abs(arr[i] - arr[i + 1]) == diff) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
        std::vector<int> vec{3, 5, 1};
//    std::vector<int> vec{1, 2, 4};
//    std::vector<int> vec{-13,-17,-8,-10,-20,2,3,-19,2,-18,-5,7,-12,18,-17,12,-1};
    Solution sol;
    std::cout << sol.canMakeArithmeticProgression(vec) << std::endl;
    return 0;
}