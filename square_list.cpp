#include <cassert>
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> process(std::vector<T> const& vec) {
    std::vector<T> result;
    if (vec.empty()) {
        return result;
    }
    result.reserve(vec.size());
    int index_separation = -1;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] >= 0) {
            index_separation = i;
            break;
        }
    }
    if (index_separation == 0) {
        for (auto item : vec) {
            result.emplace_back((item) * (item));
        }
    } else if (index_separation == -1) {
        for (auto it = vec.rbegin(); it != vec.rend(); it++) {
            result.emplace_back((*it) * (*it));
        }
    } else {
        assert(index_separation != 0);
        int left_index = index_separation - 1;
        int right_index = index_separation;
        while (left_index >= 0 || right_index != vec.size()) {
            if (left_index < 0 && right_index != vec.size()) {
                result.emplace_back(vec[right_index] * vec[right_index]);
                right_index++;
            } else if (left_index != -1 && right_index == vec.size()) {
                result.emplace_back(vec[left_index] * vec[left_index]);
                left_index--;
            } else {
                if (abs(vec[left_index]) == vec[right_index]) {
                    result.emplace_back(vec[left_index] * vec[left_index]);
                    left_index--;
                    right_index++;
                } else if (abs(vec[left_index]) > vec[right_index]) {
                    result.emplace_back(vec[right_index] * vec[right_index]);
                    result.emplace_back(vec[left_index] * vec[left_index]);
                    left_index--;
                    right_index++;
                } else if (abs(vec[left_index]) < vec[right_index]) {
                    result.emplace_back(vec[left_index] * vec[left_index]);
                    result.emplace_back(vec[right_index] * vec[right_index]);
                    left_index--;
                    right_index++;
                }
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> vec1{-5, -2, -1, 0, 1, 4,5,6,7};
    //    std::vector<int> vec1{0, 1, 4, 5, 6};
    //    std::vector<int> vec1{-5, -2, -1};
    std::vector<int> result = process(vec1);
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}