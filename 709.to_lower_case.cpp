/*
709. To Lower Case
Easy
Topics
Companies
Hint
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.



Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"


Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
 */
#include <iostream>
#include <ranges>
#include <algorithm>

class Solution {
   public:
    std::string toLowerCase(std::string s) {
        std::ranges::for_each(s,[&s](auto & symbol){
            symbol= std::tolower(symbol);
        });
        return s;
    }
};

int main() {
    std::string s{"Hello"};
    Solution sol;
    std::cout << sol.toLowerCase(s) << std::endl;
    return 0;
}