#include <iostream>
#include <windows.h>

void print_main_page()
{
    system("cls");
    std::cout << "This is a simple MBTI test.\nLet's find out your MBTI by typing on the keyboard.\n"
              << std::endl;
    std::cout << "A. Start Test " << std::endl;
    std::cout << "B. View Result " << std::endl;
    std::cout << "C. Exit " << std::endl;
    std::cout << "Enter one charcter :  ";
}

void print_test_page()
{
    system("cls");
    std::cout << "This is a simple MBTI test.\nLet's find out your MBTI by typing on the keyboard.\n"
              << std::endl;
    std::cout << "A. Start Test " << std::endl;
    std::cout << "B. View Result " << std::endl;
    std::cout << "C. Exit " << std::endl;
    std::cout << "Enter one charcter :  ";
}

void print_result(int code)
{
    if (code == 1)
    {
    }
}