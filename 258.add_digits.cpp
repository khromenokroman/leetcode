#include <iostream>
#include <vector>

/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
*/

int main()
{
    int count = 0;
    int num = 561;
    while(true)
    {
        if (num<10)
        {
            return num;
            break;
        }
        std::vector<int> data; //сюда пишем разложенные данные
        

        int n,k;

        while (num!=0) //раскладываем число
        {
            k = num%10;
            data.push_back(k);
            num = num/10;
        }

        // std::cout << "Вывод вектора: " << std::endl; //смотри мчто получилось
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << " : ";
        }
        // std::cout << "\n";

        num = 0; //обнуляем 
        for (int i = 0; i < data.size(); i++) //суммируем новое число
        {
            num += data[i] ;
        }
        // std::cout << "Сумма: " << number << std::endl;
        count++;
    }

}