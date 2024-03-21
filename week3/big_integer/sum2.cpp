#include <iostream>
#include <string>

using namespace std;

string padding(string number, int space_number);

string sum2(string num1, string num2)
{
    /* 연산을 위해 두 문자열의 자릿수를 맞춰줌 */
    if (num1.length() >= num2.length())
    {
        num2 = padding(num2, num1.length() - num2.length());
    }
    else
    {
        num1 = padding(num1, num2.length() - num1.length());
    }

    /* 덧셈 로직 */
    string result;
    int carry = 0;

    for (int i = 0; i < num1.length(); i++)
    {
        int num1_units = num1[num1.length() - i - 1] - '0';
        int num2_units = num2[num1.length() - i - 1] - '0';

        result = to_string((num1_units + num2_units + carry) % 10) + result;
        carry = num1_units + num2_units + carry >= 10 ? 1 : 0;
    }
    /* 마지막 carry 처리 */
    if (carry)
    {
        result = '1' + result;
    }

    return result;
}