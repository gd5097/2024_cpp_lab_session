#include <string>

using namespace std;

string padding(string number, int sapce_number)
{
    string result = number;

    for (int i = 0; i < sapce_number; i++)
    {
        result = '0' + result;
    }

    return result;
}