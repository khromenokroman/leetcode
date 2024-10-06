/*
242. Valid Anagram
Easy
Topics
Companies
Given two strings s and t, return true if t is an
anagram
 of s, and false otherwise.



Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false



Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

#include <iostream>
#include <ranges>
#include <algorithm>

class Solution {
   public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()){
            return false;
        }
        if(!std::ranges::is_sorted(s)){
            std::ranges::sort(s);
        }
        if (!std::ranges::is_sorted(t)) {
            std::ranges::sort(t);
        }
        for(auto i=0;i<s.size();i++){
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isAnagram("listen", "silent") << std::endl;
    std::cout << sol.isAnagram("rat", "car") << std::endl;
}