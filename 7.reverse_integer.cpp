/*
7. Reverse Integer
Medium
Topics
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the
signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1
 */

#include <iostream>
class Solution {
   public:
    int reverse(int x) {
        int answer = 0;
        int sign = 0;
        if (x == INT32_MIN) {
            return 0;
        } else if (x < 0) {
            sign = -1;
            x = -x;
        } else if (x > 0) {
            sign = 1;
        } else {
            return 0;
        }

        while (x) {
            if (answer < INT32_MAX / 10 || answer == INT32_MAX / 10 && x % 10 <= INT32_MAX / 10) {
                answer = answer * 10 + x % 10;
                x /= 10;
            } else {
                return 0;
            }
        }
        return answer * sign;
    }
};

int main() {
    Solution sol;
    //        int number = 123;
    //    int number = 2147483647;
    int number = -2147483647;
    //    int number = 2147483648;
    //    int number = -12;
    std::cout << "reverse(" << number << "): " << sol.reverse(number) << std::endl;
    return 0;
}