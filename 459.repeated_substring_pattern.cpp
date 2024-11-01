/*
 459. Repeated Substring Pattern
Easy
Topics
Companies
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the
substring together.



Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 */
#include <iostream>
#include <stack>

class Solution {
   public:
    bool repeatedSubstringPattern(std::string s) {
        std::string new_str = s + s;
        auto new_s = new_str.substr(1, new_str.size() - 2);
        return new_s.find(s) != std::string::npos;
    };
};
int main() {
    //    std::string s{"abab"};
    //        std::string s{"abcabcabcabc"};
    //        std::string s{"aba"};
    std::string s{"ababba"};
    Solution sol;
    std::cout << sol.repeatedSubstringPattern(s) << std::endl;
    return 0;
}