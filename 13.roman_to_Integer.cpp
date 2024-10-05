/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

class Solution {
    std::vector<char> m_vec_char{100};
    std::vector<int> m_vec_int{100};

   public:
    enum class INTEGER { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 };

    void fill_vec_char(std::string const& str) {
        std::ranges::for_each(str, [this](char symbol) { m_vec_char.emplace_back(symbol); });
    }

    static int convert_cahr_to_int(char const symbol) {
        switch (symbol) {
            case 'I':
                return static_cast<int>(INTEGER::I);
            case 'V':
                return static_cast<int>(INTEGER::V);
            case 'X':
                return static_cast<int>(INTEGER::X);
            case 'L':
                return static_cast<int>(INTEGER::L);
            case 'C':
                return static_cast<int>(INTEGER::C);
            case 'D':
                return static_cast<int>(INTEGER::D);
            case 'M':
                return static_cast<int>(INTEGER::M);
            default:
                return 0;
        }
    }

    void correct_vec() {
        for (auto i = 0; i < m_vec_char.size(); i++) {
            if (i == 0) {
                m_vec_int[i] = convert_cahr_to_int(m_vec_char[i]);
                continue;
            }
            if ((m_vec_char[i] == 'V' or m_vec_char[i] == 'X') and m_vec_char[i - 1] == 'I') {
                if (m_vec_char[i] == 'V') {
                    m_vec_int[i - 1] = 0;
                    m_vec_int.emplace_back(convert_cahr_to_int('V') - convert_cahr_to_int('I'));
                    continue;
                }
                if (m_vec_char[i] == 'X') {
                    m_vec_int[i - 1] = 0;
                    m_vec_int.emplace_back(convert_cahr_to_int('X') - convert_cahr_to_int('I'));
                    continue;
                }
            }
            if ((m_vec_char[i] == 'L' or m_vec_char[i] == 'C') and m_vec_char[i - 1] == 'X') {
                if (m_vec_char[i] == 'L') {
                    m_vec_int[i - 1] = 0;
                    m_vec_int.emplace_back(convert_cahr_to_int('L') - convert_cahr_to_int('X'));
                    continue;
                }
                if (m_vec_char[i] == 'C') {
                    m_vec_int[i - 1] = 0;
                    m_vec_int.emplace_back(convert_cahr_to_int('C') - convert_cahr_to_int('X'));
                    continue;
                }
            }
            if ((m_vec_char[i] == 'D' or m_vec_char[i] == 'M') and m_vec_char[i - 1] == 'C') {
                if (m_vec_char[i] == 'D') {
                    m_vec_int[i - 1] = 0;
                    m_vec_int.emplace_back(convert_cahr_to_int('D') - convert_cahr_to_int('C'));
                    continue;
                }
                if (m_vec_char[i] == 'M') {
                    m_vec_int[i - 1] = 0;
                    m_vec_int.emplace_back(convert_cahr_to_int('M') - convert_cahr_to_int('C'));
                    continue;
                }
            }
            m_vec_int.emplace_back(convert_cahr_to_int(m_vec_char[i]));
        }
    }

    int romanToInt(std::string const& str) {
        fill_vec_char(str);
        correct_vec();
        std::cout << "m_vec_char: ";
        std::ranges::for_each(m_vec_char, [](auto const& item) { std::cout << item << " "; });
        std::cout << std::endl;
        std::cout << "m_vec_int: ";
        std::ranges::for_each(m_vec_int, [](auto const& item) { std::cout << item << " "; });
        std::cout << std::endl;
        int sum = 0;
        std::ranges::for_each(m_vec_int, [&sum](auto const& item) { sum += item; });
        return sum;
    }
};

int main() {
    Solution a;

    //    std::cout << a.romanToInt("III") << std::endl;     // 3
    //    std::cout << a.romanToInt("IVI") << std::endl;     // 4
    //    std::cout << a.romanToInt("LVIII") << std::endl;   // 58
    std::cout << a.romanToInt("MCMXCIV") << std::endl; // 1994
}