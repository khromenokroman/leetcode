/*
 20. Valid Parentheses
Easy
Topics
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true



Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <stack>
#include <string>

class Solution {
   public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (auto const& symbol : s) {
            switch (symbol) {
                case '(':
                    stack.emplace(symbol);
                    break;
                case '{':
                    stack.emplace(symbol);
                    break;
                case '[':
                    stack.emplace(symbol);
                    break;
                case ')':
                    if (!stack.empty() && stack.top() == '(') {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!stack.empty() && stack.top() == '{') {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!stack.empty() && stack.top() == '[') {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    //    std::string s{"()"};
    //    std::string s{"(]"};
    std::string s{"([])"};
    Solution sol;
    std::cout << sol.isValid(s) << std::endl;
    return 0;
}