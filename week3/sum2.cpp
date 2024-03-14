#include <iostream>
#include <string>

using namespace std;

string sum2(string num1, string num2)
{
    string result;

    while (num1.length() != 0 && num2.length() != 0)
    {
        int num1_last_number = num1[0] - '0';
        int num2_last_number = num2[0] - '0';

        cout << "C1 : " << num1_last_number << endl;
        cout << "C2 : " << num2_last_number << endl;

        result = to_string((num1_last_number + num2_last_number) % 10) + result;

        cout << result
    }

    return num1 + num2;
}