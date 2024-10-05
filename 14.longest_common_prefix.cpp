/*
14. Longest Common Prefix
Easy
Topics
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""

Explanation: There is no common prefix among the input strings.
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

class Solution {
   public:
    static void sotr_vector(std::vector<std::string>& vector_words) {
        if (!std::ranges::is_sorted(vector_words, [](std::string const& l_data, std::string const& r_data) {
                return l_data.size() < r_data.size();
            })) {
            std::ranges::sort(vector_words, [](std::string const& l_data, std::string const& r_data) {
                return l_data.size() < r_data.size();
            });
        };
    };

    std::string find_prefix(std::vector<std::string>& vector_words) {
        std::string prefix{};
        bool end{false};
        std::string first_word = vector_words[0];
        std::ranges::for_each(std::views::iota(0) | std::views::take(first_word.size()),
                              [&end, &first_word, &vector_words, &prefix](auto const& i) {
                                  if (!end) {
                                      char symbol = first_word[i];
                                      std::ranges::for_each(vector_words, [&symbol, &i, &end](std::string const& word) {
                                          if (symbol != word[i]) {
                                              end = true;
                                          }
                                      });
                                      if(!end){
                                          prefix += first_word[i];
                                      }
                                  }
                              });
        return prefix;
    }

    // Альтернативный вариант
    /*std::string find_prefix(std::vector<std::string>& vector_words) {
        std::string prefix{};
        bool end{false};
        std::string first_word = vector_words[0];
        for (auto i = 0; i < first_word.size(); i++) {
            if (end) {
                break;
            }
            char symbol = first_word[i];
            std::ranges::for_each(vector_words, [&symbol, &i, &end](std::string const& word) {
                if (symbol != word[i]) {
                    end = true;
                }
            });
            if (!end) {
                prefix += first_word[i];
            }
        }
        return prefix;
    }*/

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        sotr_vector(strs);
        return find_prefix(strs);
    }
};

int main() {
    Solution sol;
        std::vector<std::string> input = {"flower", "flow", "flight"};
//    std::vector<std::string> input = {"dog", "racecar", "car"};
    std::cout << "res: " << sol.longestCommonPrefix(input) << std::endl;
    std::ranges::for_each(input, [](std::string const& word) { std::cout << word << " "; });
    std::cout << std::endl;
}