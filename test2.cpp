#include <cstring>
#include <iostream>

class Test {
   public:
    explicit Test(uint64_t size) : m_size{size}, m_array{new int[m_size]} {
        std::cout << this << " constr" << std::endl;
    }
    ~Test() {
        if (m_array) {
            delete[] m_array;
        }
        std::cout << this << " destr" << std::endl;
    }
    Test(Test const& other) : m_size{other.m_size}, m_array{new int[other.m_size]} {
        std::cout << this << " copy constr" << std::endl;
        std::memcpy(this->m_array, other.m_array, other.m_size);
    }
    Test& operator=(Test const& other) {
        std::cout << this << " copy operator=" << std::endl;
        if (this == &other) {
            return *this;
        }

        auto tmp_ptr = new int[other.m_size];
        if (this->m_array) {
            delete[] this->m_array;
        }
        this->m_array = tmp_ptr;
        this->m_size = other.m_size;
        std::memcpy(this->m_array, other.m_array, other.m_size);

        return *this;
    }
    Test(Test&& other) noexcept : m_size{other.m_size}, m_array{std::move(other.m_array)} {
        std::cout << this << " move copy" << std::endl;
        other.m_array = nullptr;
    }
    Test& operator=(Test&& other) noexcept {
        std::cout << this << " move operator=" << std::endl;
        if (this == &other) {
            return *this;
        }

        if (this->m_array) {
            delete[] this->m_array;
        }
        this->m_array = std::move(other.m_array);
        other.m_array = nullptr;
        this->m_size = other.m_size;
        other.m_size = 0;

        return *this;
    }

    void fill_array() {
        for (uint64_t i = 0; i < m_size; i++) {
            m_array[i] = std::rand() % 100;
        }
    }

    void print_array() {
        std::cout << this << ":\t";
        for (uint64_t i = 0; i < m_size; i++) {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

   private:
    uint64_t m_size = 0;    // 8
    int* m_array = nullptr; // 8
};

Test foo() {
    Test t(2);

    return t;
}

int main() {
    Test a(10), b(20);

    a.fill_array();
    a.print_array();

    auto c = foo();
    c.print_array();
    a = b;
    a.print_array();

    return 0;
}
