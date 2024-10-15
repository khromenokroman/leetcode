/*
 58. Length of Last Word
Easy
Topics
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
 consisting of non-space characters only.



Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
 */

#include <iostream>
#include <vector>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        auto pos = s.find(' ');
        if (pos == std::string::npos) {
            return s.size();
        }
        size_t index_head = -1, index_tail = -1;
        for (auto i = s.size() - 1; i != -1; i--) {
            if (index_tail != -1 and s[i] == ' ') {
                index_head = i + 1;
                break;
            }
            if (index_tail != -1) {
                continue;
            }
            if (s[i] != ' ') {
                index_tail = i;
            }
        }
        if (index_head == -1) {
            return static_cast<int>(-(0 - index_tail - 1));
        } else {
            return static_cast<int>(-(index_head - index_tail - 1));
        }
    }
};
int main() {
    //        std::string s{"Hello World"};
    //        std::string s{"a "};
    //    std::string s{"ab "};
    //            std::string s{"   fly me   to   the moon  "};
//    std::string s{"luffy is still joyboy"};
    std::string s{"a"};
    Solution sol;
    std::cout << sol.lengthOfLastWord(s) << std::endl;
    return 0;
}