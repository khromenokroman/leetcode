#include <cassert>
#include <iostream>

namespace test_template {

// template <typename T1, typename T2>
// auto max(T1 const& one, T2 const& two) -> typename std::decay<decltype(one > two ? one : two)>::type {
//     return one > two ? one : two;
// }
//template <typename T1, typename T2>
//std::common_type<T1, T2>::type max(T1 const& one, T2 const& two) {
//    return one > two ? one : two;
//}
template <typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 const& one, T2 const& two) {
    return one > two ? one : two;
}
} // namespace test_template

int main() {
    std::cout << ::test_template::max(10, 10) << std::endl;
    std::cout << ::test_template::max<double>(8.2, 9.1) << std::endl;
    std::cout << ::test_template::max(8.2, 9) << std::endl;
    return 0;
}