#include <iostream>
#include <variant>

int main() {
    constexpr std::variant<int, char> test{'s'};
    constexpr auto a = test.index();
    constexpr auto b =get<a>(test) ;
    std::cout << b << std::endl;

    return 0;
}