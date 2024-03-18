#include <iostream>
#include <string>

#define NUM1_IS_BIGGER 0
#define NUM2_IS_BIGGER 1
#define SAME 2

using namespace std;

string padding(string number, int space_number);

int is_bigger_than(string num1, string num2)
{
    /* 자릿수가 같은 수에대한 대소 판별
     * 0: num1이 큼
     * 1: num2가 큼
     * 2: 두 수가 같음
     */
    for (int i = 0; i < num1.length(); i++)
    {
        if (num1[i] > num2[i])
        {
            return NUM1_IS_BIGGER;
        }
        else if (num1[i] < num2[i])
        {
            return NUM2_IS_BIGGER;
        }
    }

    return SAME;
}

void remove_unnecessary_zeroes(string &number)
{
    while (number.length() != 0)
    {
        if (number[0] == '0')
        {
            number.erase(0, 1);
        }
        else
        {
            return;
        }
    }
}

string sub2(string num1, string num2)
{
    string big_number;
    string small_number;
    bool is_minus = false; // 연산 결과가 minus인지 결정

    /* 두 수중 무엇이 더 큰 수인지 판별
     * 패딩까지 수행
     * 두 수가 같은 경우 0을 반환
     */
    if (num1.length() > num2.length())
    {
        big_number = num1;
        small_number = padding(num2, num1.length() - num2.length());
        is_minus = false;
    }
    else if (num1.length() < num2.length())
    {
        big_number = num2;
        small_number = padding(num1, num2.length() - num1.length());
        is_minus = true;
    }
    else if (num1.length() == num2.length())
    {
        int which_is_bigger = is_bigger_than(num1, num2);

        if (which_is_bigger == NUM1_IS_BIGGER)
        {
            big_number = num1;
            small_number = num2;
            is_minus = false;
        }
        else if (which_is_bigger == NUM2_IS_BIGGER)
        {
            big_number = num2;
            small_number = num1;
            is_minus = true;
        }
        else if (which_is_bigger == SAME)
        {
            is_minus = false;
            return "0";
        }
    }

    /* 뺄셈 로직 */
    string result;
    int borrow = 0;

    for (int i = 0; i < big_number.length(); i++)
    {
        int big_number_units = big_number[big_number.length() - i - 1] - '0';
        int small_number_units = small_number[big_number.length() - i - 1] - '0';

        /* 빌림수가 있는 경우와 없는 경우를 각각 셋팅*/
        if (big_number_units - small_number_units - borrow < 0)
        {
            result = to_string(big_number_units - small_number_units - borrow + 10) + result;
            borrow = 1;
        }
        else
        {
            result = to_string(big_number_units - small_number_units - borrow) + result;
            borrow = 0;
        }
    }

    remove_unnecessary_zeroes(result);

    /* minus 적용 */
    if (is_minus)
    {
        result = "-" + result;
    }

    return result;
}