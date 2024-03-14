#include <iostream>
#include <string>

using namespace std;

string sum2(string num1, string num2)
{
    string result;
    int carry = 0;

    for (int i = 0; i < num1.length(); i++)
    {
        int num1_units = num1[i] - '0';
        int num2_units = num2[i] - '0';

        result = result + to_string((num1_units + num2_units + carry) % 10);
        carry = num1_units + num2_units + carry >= 10 ? 1 : 0;
    }

    return result;
}