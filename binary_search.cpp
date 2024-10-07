#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>

constexpr int ARR_SIZE = 7;
constexpr int SEARCH_NUMBER = 12;

int main() {
    std::array<int, ARR_SIZE> arr{1, 3, 5, 7, 9, 10, 12}; // 1 3 5 7 9 10 12
    std::ranges::sort(arr);

    auto print = [](auto const& item) { std::cout << item << " "; };
    std::ranges::for_each(arr, print);
    std::cout << std::endl;

    int head = 0, tail = ARR_SIZE - 1, mid = 0;
    bool find_flag{false};

    while (head <= tail) {
        mid = (head + tail) / 2;
        if (arr[mid] == SEARCH_NUMBER) {
            find_flag = true;
            break;
        }
        if (arr[mid] > SEARCH_NUMBER) {
            tail = mid - 1;
        }
        if (arr[mid] < SEARCH_NUMBER) {
            head = mid + 1;
        }
    }
    std::cout << "find_flag: " << find_flag << std::endl;
    return 0;
}