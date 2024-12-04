#include <cassert>
#include <iostream>
#include <vector>

int get_smal_index(std::vector<int> const& vec) {
    assert(!vec.empty());
    int smal_number = vec[0];
    int smal_index = 0;
    for (auto i = 1; i < vec.size(); i++) {
        if (vec[i] < smal_number) {
            smal_number = vec[i];
            smal_index = i;
        }
    }
    return smal_index;
}

void sortVib(std::vector<int>& vec) {
    std::vector<int> temp;
    temp.reserve(vec.size());
    while (!vec.empty()) {
        auto smal_index = get_smal_index(vec);
        temp.push_back(vec[smal_index]);
        vec.erase(vec.begin() + smal_index);
    }

    vec = std::move(temp);
}

int main() {
    std::vector<int> vec{1, 4, 5, 78, 3, 1, 13, 45, 6, 7, 8};
    for (auto const& item : vec) {
        std::cout << item << " ";
    }
    std::cout << '\n'<<'\n';
    sortVib(vec);
    for (auto const& item : vec) {
        std::cout << item << " ";
    }
    std::cout << '\n';
    return 0;
}