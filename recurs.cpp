#include <iostream>

void print(int number) {
    std::cout << "number: " << number << std::endl;
    if (number == 0) {
        return;
    } else {
        print(number - 1);
    }
}

int fact(int number) {
    if (number == 0) {
        return 1;
    } else {
        return number * fact(number - 1);
    }
}

int main() {
    std::cout << fact(3) << std::endl;
    // int number = 9000;
    // print(number);
    return 0;
}