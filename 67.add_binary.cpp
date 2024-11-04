/*
67. Add Binary
Easy
Topics
Companies
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <algorithm>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string addBinary(std::string a, std::string b) {
        if (a == "0" && b == "0") {
            return "0";
        }
        int size_a = a.size();
        int size_b = b.size();
        int max_size = std::max(size_a, size_b);
        std::string result(size_a + size_b, '0');
        int overflow = 0;
        size_a--;
        size_b--;

        for (int i = result.size() - 1; i >= 0; i--, size_a--, size_b--) {
            int sum = 0;
            if (size_a < 0 && size_b < 0) {
                if (overflow == 1) {
                    result[i] = 1 + '0';
                }
                overflow = 0;
            } else if (size_a < 0) {
                sum = b[size_b] - '0' + overflow;
                if (sum >= 2) {
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                if (sum == 2) {
                    result[i] = 0 + '0';
                } else if (sum == 1) {
                    result[i] = 1 + '0';
                } else {
                    result[i] = 0 + '0';
                }
            } else if (size_b < 0) {
                sum = a[size_a] - '0' + overflow;
                if (sum >= 2) {
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                if (sum == 2) {
                    result[i] = 0 + '0';
                } else if (sum == 1) {
                    result[i] = 1 + '0';
                } else {
                    result[i] = 0 + '0';
                }
            } else {
                sum = (a[size_a] - '0') + (b[size_b] - '0') + overflow;
                if (sum >= 2) {
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                if (sum == 3) {
                    result[i] = 1 + '0';
                } else if (sum == 2) {
                    result[i] = 0 + '0';
                } else if (sum == 1) {
                    result[i] = 1 + '0';
                } else {
                    result[i] = 0 + '0';
                }
            }
        }
        auto pos = result.find_first_not_of('0');
        return result.substr(pos);
    }
};

int main() {
    Solution sol;
    std::cout << sol.addBinary("10", "1") << std::endl;
    std::cout << sol.addBinary("11", "1") << std::endl;
    std::cout << sol.addBinary("11", "11") << std::endl;
    std::cout << sol.addBinary("11", "10") << std::endl;
    return 0;
}
