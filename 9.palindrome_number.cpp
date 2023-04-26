#include <iostream>
#include <vector>

/*
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

int main()
{
    int number_orig = 1234567899;
    if (number_orig < 0)
        return false;
    if (number_orig == 0)
        return true;
    int number = number_orig;
    int data_char;
    std::string data_str;

    std::vector<int> data;

    while (number != 0) //заполним вектор числами
    {
        data.push_back(number % 10);
        number = number / 10;
    }

    for (int i = 0; i < data.size(); i++) //посмотрим что получилось
    {
        std::cout << data[i] << std::endl;
    }

    for (int i = 0; i < data.size(); i++) //добавим в строку числа
    {
        data_str += std::to_string(data[i]);
    }
    
    std::cout << data_str << std::endl;
    int data_int = std::stol(data_str); //превратим строку в числа :)
    if (data_int == number_orig)
    {
        std::cout << "Полиндром" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Не полиндром" << std::endl;
        return false;
    }    
}

