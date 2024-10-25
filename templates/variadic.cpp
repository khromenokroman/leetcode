#include <array>
#include <iostream>
#include <vector>

namespace variadic {
template <typename T>
void print(T str) {
    std::cout << "print T: " << str << std::endl;
}

template <typename T, typename... Types>
void print(T str, Types... other) {
    std::cout << "last type: " << sizeof...(Types) << " last value: " << sizeof...(other) << std::endl;
    std::cout << str << std::endl;
    print(other...);
}

} // namespace variadic

namespace bin_three {
struct Node {
    Node* m_left;
    Node* m_right;
    int m_value;
    explicit Node(int value) : m_value{value}, m_left{nullptr}, m_right{nullptr} {};
};
auto left = &Node::m_left;
auto right = &Node::m_right;

template <typename T, typename... Types>
Node* go(T one, Types... args) {
    return (one->*...->*args);
}
} // namespace bin_three
namespace print_templ {
template <typename T>
struct Add_space {
    T const& m_ref;
    explicit Add_space(T const& ref) : m_ref{ref} {};
    friend std::ostream& operator<<(std::ostream& ostream, Add_space const& object) {
        return ostream << object.m_ref << " ";
    }
};
template <typename... T>
void print(T... args) {
    (std::cout << ... << Add_space{args});
}
} // namespace print_templ

namespace double_print {
struct Test {
    explicit Test(int number) : m_number{number} {};
    int m_number;
    Test operator+(Test const& other) const { return Test{m_number + other.m_number}; }
    friend std::ostream& operator<<(std::ostream& ostream, Test const& object) {
        return ostream << object.m_number << std::endl;
    }
};
template <typename... T>
void print(T const&... values) {
    (std::cout << ... << values);
}
template <typename... T>
void double_print(T const&... values) {
    print(values + values...);
}
} // namespace double_print
namespace homo {
template <typename T1, typename... T2>
constexpr bool is_homogenius(T1, T2...) {
    return (std::is_same_v<T1, T2> && ...);
}
} // namespace homo
namespace variadic2 {
template <typename T>
struct Add_space {
    T const& m_ref;
    explicit Add_space(T const& ref) : m_ref{ref} {};
    friend std::ostream& operator<<(std::ostream& os, Add_space const& object) { return os << object.m_ref << " "; }
};
template <typename... T>
void print_index(T... args) {
    (std::cout << ... << Add_space{args});
}
template <ssize_t... INDEX, typename T>
void print(T const& data) {
    (print_index(data[INDEX]...));
}
} // namespace variadic2
namespace sum_templ {
template <typename T>
constexpr int sum_pack(T const& value) {
    return value;
}
template <typename T, typename... T1>
constexpr int sum_pack(T const& value, T1 const&... values) {
    return value + sum_pack(values...);
}
template <int... INDEX, typename Type_array>
constexpr int sum_templ(Type_array const& array) {
    return sum_pack(array[INDEX]...);
}

} // namespace sum_templ
int main() {
    constexpr std::array<int, 4> data{0, 1, 2, 3};
    constexpr int sum = sum_templ::sum_templ<0, 1, 2, 3>(data);
    std::cout << "sum: " << sum << std::endl;

    //    std::vector<std::string> data{"roma", "roma1", "roma2", "roma3"};
    //    variadic2::print<0, 1>(data);

    //    std::cout << "homo: " << homo::is_homogenius(1, 2) << std::endl;
    //    std::cout << "homo: " << homo::is_homogenius(1, 2.2) << std::endl;
    //    std::cout << "homo: " << homo::is_homogenius(1, "asdf") << std::endl;
    //    std::cout << "homo: " << homo::is_homogenius(std::string("asdf"), "asdf") << std::endl;
    //    //    double_print::double_print(0, 1, 2);
    //    auto a = double_print::Test{0};
    //    auto b = double_print::Test{1};
    //    auto c = double_print::Test{2};
    //    double_print::double_print(a, b, c);

#pragma region bin_three

    //    auto* node_root = new bin_three::Node{0};
    //    node_root->m_left = new bin_three::Node{1};
    //    node_root->m_left->m_right = new bin_three::Node{2};
    //    auto node = go(node_root, bin_three::left, bin_three::right);
    //    delete node_root->m_left->m_right;
    //    delete node_root->m_left;
    //    delete node_root;
    //    std::cout << "node: " << node->m_value << std::endl;

#pragma endregion

    //    { variadic::print("roma", "roma1", "roma2", "roma3"); }
    //
    //    print_templ::print("Hello", "World");
    return 0;
}