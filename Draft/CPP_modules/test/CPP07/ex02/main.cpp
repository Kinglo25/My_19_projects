#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10000
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> a(2);
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        a = tmp;
        for (int i = 0; i < MAX_VAL - 1; i++)
        {
            std::cout << numbers[i] << " | ";
            std::cout << tmp[i] << " | ";
            tmp[i] = 0;
            std::cout << a[i] << " | ";
            std::cout << test[i] << std::endl;
        }
        std::cout << std::endl << "Testing to change the value of one array and checking if the arays its copied from didnt change : " << std::endl;
        for (int i = 0; i < MAX_VAL - 1; i++)
        {
            std::cout << numbers[i] << " | ";
            std::cout << tmp[i] << std::endl;
        }
    }
    std::cout << std::endl << "Testing if mirror and numbers are correctly equalized, dont send back anything if its the case : " << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << std::endl << "Testing Exeption if value in brackets is bad : " << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "Checking if every value is correctly attributed in numbers : " << std::endl;
    for (int i = 0; i < MAX_VAL - 1; i++)
    {
        numbers[i] = rand();
        std::cout << numbers[i] << ", ";
    }
    std::cout << numbers[MAX_VAL - 1] << std::endl;
    std::cout << "Testing the size fonction : " << numbers.size() << std::endl;
    delete [] mirror;
    return 0;
}