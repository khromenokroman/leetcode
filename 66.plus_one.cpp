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
#include <ranges>
#include <vector>
#include <list>

class Solution {
   public:
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> vec;
        vec.reserve(digits.size() + 1);
        std::list<int> list;

        int overflow = 0, sum = 0;
        for (auto i = static_cast<int>(digits.size()) - 1; i >= 0; i--) {
            if (overflow == 0 and i == digits.size() - 1) {
                sum = digits[i] + 1;
                if (sum >= 10) {
                    overflow = 1;
//                    std::cout << 0 << " ";
                    list.push_front(0);
                } else {
                    overflow = 0;
//                    std::cout << sum << " ";
                    list.push_front(sum);
                }
            } else if (overflow == 0) {
                overflow = 0;
//                std::cout << digits[i] << " ";
                list.push_front(digits[i]);
            } else {
                sum = digits[i] + 1;
                if (sum >= 10) {
                    overflow = 1;
//                    std::cout << 0 << " ";
                    list.push_front(0);
                } else {
                    overflow = 0;
//                    std::cout << sum << " ";
                    list.push_front(sum);
                }
            }
        }
        if(overflow == 1){
//            std::cout << 1 << " ";
            list.push_front(1);
        }
        std::cout << std::endl;

//        auto print = [](auto const& item) { std::cout << item << " "; };
//        std::ranges::for_each(list, print);

        std::ranges::for_each(list, [&vec](auto & item){vec.emplace_back(std::move(item));});

        return vec;
    }
};

int main() {
    Solution sol;
//    std::vector<int> vec_digits{9, 9, 9, 9, 9};
    std::vector<int> vec_digits{1, 2, 3, 4, 9};
    auto print = [](auto const& item) { std::cout << item << " "; };

    std::ranges::for_each(vec_digits, print);
    std::cout << std::endl;

    auto new_vec = sol.plusOne(vec_digits);
    std::ranges::for_each(new_vec, print);
    std::cout << std::endl;
}