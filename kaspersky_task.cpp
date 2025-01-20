/*
Дана последовательность символов. Способ представления последовательности
не оговаривается. Необходимо разбить указанную последовательность на
подпоследовательности, используя задаваемый символ в качестве разделителя.
Последовательные разделители нужно пропускать (т.е. подпоследовательностей
нулевой длины в результате быть не должно). Способ дальнейшего использования
подпоследовательностей не оговаривается.

Пример одного из сценариев использования:
input: "some text with delimiters"
delimiter: ' '
output: "some", "text", "with", "delimiters"
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T1, typename T2>
auto fill_vec(T1 const& text, T2 delimiter) {
    ::std::vector<T1> result;
    if constexpr (::std::is_same_v<T1, ::std::string>) {
        ::std::istringstream stream{text};
        ::std::string token{};
        while (::std::getline(stream, token, delimiter)) {
            if (!token.empty()) {
                result.emplace_back(std::move(token));
            }
        }
    } else if constexpr (::std::is_same_v<T1, ::std::wstring>) {
        ::std::wistringstream stream{text};
        ::std::wstring token{};
        while (::std::getline(stream, token, delimiter)) {
            if (!token.empty()) {
                result.emplace_back(std::move(token));
            }
        }
    } else {
        static_assert(std::is_same_v<T1, std::string> || std::is_same_v<T1, std::wstring>,
                      "fill_vec supports only std::string and std::wstring.");
    }
    return result;
}

int main() {
    ::std::string s{"some text with delimiters"};
    char delimiter{' '};

    auto tokens = fill_vec(s, delimiter);

    for (auto const& word : tokens) {
        std::cout << word << std::endl;
    }

    return 0;
}