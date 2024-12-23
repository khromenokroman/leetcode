#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

std::vector<int> qsort(std::vector<int> const& arr) {
    if (arr.empty()) {
        return arr;
    }
    if (arr.size() == 1) {
        return arr;
    }

    std::vector<int> left;
    std::vector<int> right;
    int pivot = arr[0];

    for (auto i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) {
            left.emplace_back(arr[i]);
        } else {
            right.emplace_back(arr[i]);
        }
    }

    std::vector<int> res = qsort(left);
    res.emplace_back(pivot);
    std::vector<int> res2 = qsort(right);
    res.insert(res.end(), res2.begin(), res2.end());
    return res;
}

void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& arr) {
    size_t ind_left = 0;
    size_t ind_right = 0;
    size_t ind_arr = 0;
    while (ind_left < left.size() && ind_right < right.size()) {
        if (left[ind_left] < right[ind_right]) {
            arr[ind_arr++] = left[ind_left++];
        } else {
            arr[ind_arr++] = right[ind_right++];
        }
    }
    while (ind_left < left.size()) {
        arr[ind_arr++] = left[ind_left++];
    }
    while (ind_right < right.size()) {
        arr[ind_arr++] = right[ind_right++];
    }
}

void msort(std::vector<int>& arr) {
    if (arr.size() < 2) {
        return;
    }
    size_t border = arr.size() / 2;

    // add vector left
    std::vector<int> left;
    left.reserve(border);
    for (auto i = 0; i < border; i++) {
        left.emplace_back(arr[i]);
    }

    // add vector right
    std::vector<int> right;
    right.reserve(arr.size() - border);
    for (auto i = border; i < arr.size(); i++) {
        right.emplace_back(arr[i]);
    }

    // recursive sort
    msort(left);
    msort(right);

    // merge
    merge(left, right, arr);
}

int main() {
    std::vector<int> arr{0, 10, 2, 5, 4, 3, 1, 6, 7, 8, 9};
    // auto vec = qsort(arr);
    msort(arr);
    for (auto const item : arr) {
        std::cout << item << '\t';
    }
    std::cout << std::endl;
}