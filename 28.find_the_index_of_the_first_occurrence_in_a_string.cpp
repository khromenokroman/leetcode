/*
 28. Find the Index of the First Occurrence in a String
Easy
Topics
Companies
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
 */

#include <iostream>

class Solution {
   public:
    int strStr(std::string haystack, std::string needle) {
        auto pos = haystack.find(needle);
        if (pos == std::string::npos) {
            return -1;
        } else {
            return static_cast<int>(pos);
        }
    }
};

int main() {
    Solution sol;
    std::cout << sol.strStr("sadbutsad", "sad") << std::endl;
    std::cout << sol.strStr("sssadbutsad", "sad") << std::endl;
    std::cout << sol.strStr("sssadbutsad", "sad0") << std::endl;
    return 0;
}
