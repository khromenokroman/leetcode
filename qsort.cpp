#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

void merge_data(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result) {
    size_t left_index = 0;
    size_t right_index = 0;
    size_t result_index = 0;
    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] < right[right_index]) {
            result[result_index++] = left[left_index++];
        } else {
            result[result_index++] = right[right_index++];
        }
    }
    while (left_index < left.size()) {
        result[result_index++] = left[left_index++];
    }
    while (right_index < right.size()) {
        result[result_index++] = right[right_index++];
    }
}

void msort(std::vector<int> &result) {
    if (result.size() < 2) {
        return;
    }
    // чтобы не было лишних аллокаций
    std::vector<int> left;
    left.reserve(result.size());
    std::vector<int> right;
    right.reserve(result.size());

    // распределение элементов
    int border = result.size() / 2;
    for (auto i = 0; i < result.size(); i++) {
        if (i < border) {
            left.emplace_back(result[i]);
        } else {
            right.emplace_back(result[i]);
        }
    }

    // сортировка
    msort(left);
    msort(right);

    // надежда что все будет ок
    assert(left.size() + right.size() == result.size());

    // объеденим данные
    merge_data(left, right, result);
}

void qsort(std::vector<int> &result) {
    if (result.size() < 2) {
        return;
    }
    // чтобы не было лишних аллокаций
    std::vector<int> less;
    less.reserve(result.size());
    std::vector<int> greater;
    greater.reserve(result.size());

    // распределение элементов
    int border = result[0];
    for (auto i = 1; i < result.size(); i++) {
        if (result[i] < border) {
            less.emplace_back(result[i]);
        } else {
            greater.emplace_back(result[i]);
        }
    }

    // сортировка
    qsort(less);
    qsort(greater);

    // надежда что все будет ок
    assert(less.size() + greater.size() + 1 == result.size());

    // заполним результирующий массив
    size_t index_result = 0;
    for (auto item : less) {
        result[index_result++] = item;
    }
    result[index_result++] = border; // если тут будет массив то довить надо его весь
    for (auto item : greater) {
        result[index_result++] = item;
    }
}

int main() {
    std::vector<int> arr{123,12,3,5,77,8,2,345,7,4,2,2,0};
    // qsort(arr);
    msort(arr);
    for (auto const item : arr) {
        std::cout << item << '\t';
    }
    std::cout << std::endl;
}