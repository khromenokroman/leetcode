/*
 43. Multiply Strings
Medium
Topics
Companies
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also
represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 */
#include <cmath>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0"){
            return "0";
        }

        int size1 = static_cast<int>(num1.size() - 1);
        int size2 = static_cast<int>(num2.size() - 1);
        std::string res(size2 + size1 +2, '0');
        for (auto s : res){
            std::cout << s;
        }
        std::cout << "\n";

        for (auto i = size1; i >= 0; i--) {
            for (auto j = size2; j >= 0; j--) {
                int mult = (num1[i] - '0') * (num2[j] - '0');
                int sum = mult + (res[i + j + 1] - '0');
                res[i + j + 1] = static_cast<char>(sum % 10 + '0');
                res[i + j] += sum / 10;
            }
        }
        auto index = res.find_first_not_of('0');
        return res.substr(index);
    }
};



int main() {
    Solution sol;
    std::cout << "multiply: " << sol.multiply("12", "10") << '\n';
}