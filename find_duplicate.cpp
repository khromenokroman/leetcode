#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
std::vector<T> process(std::vector<T> const& vec1, std::vector<T> const& vec2) {
    std::vector<T> vec;
    vec.reserve(vec1.size() + vec2.size());

    std::unordered_map<T, int> dict;

    for (auto i = 0; i < vec1.size(); i++) {
        dict[vec1[i]] += 1;
    }
    for (auto i = 0; i < vec2.size(); i++) {
        if (auto it = dict.find(vec2[i]); it != dict.end() && it->second > 0) {
            vec.emplace_back(vec2[i]);
            dict[vec2[i]] -= 1;
        }
    }
    return std::move(vec);
}

int main() {
    //    std::vector<int> vec1{1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8};
    //    std::vector<int> vec2{1, 23, 4, 5, 6, 7, 6, 8};
    std::vector<std::string> vec1{"123", "11", "12", "1234", "11"};
    std::vector<std::string> vec2{"11", "22", "12", "11", "1"};
    auto res_vec = process(vec1, vec2);

    for (auto const& item : res_vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}
