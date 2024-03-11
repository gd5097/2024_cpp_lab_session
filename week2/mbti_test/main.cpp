#include <iostream>
#include <windows.h>
#include <string>

void print_main_page();
int test();
void print_result(int code);

int main()
{
    char input;
    int test_result;

    while (1)
    {
        print_main_page();
        std::cin >> input;

        if (input == 'a' || input == 'A')
        {
            test_result = test();
        }
        else if (input == 'b' || input == 'B')
        {
            print_result(test_result);
        }
        else if (input == 'c' || input == 'C')
        {
            return 0;
        }
        else
        {
            std::cout << "Error!" << std::endl;

            return 0;
        }
    }

    return 0;
}