#include <iostream>
#include <string>

using namespace std;

string sum2(string num1, string num2);
string sub2(string num1, string num2);

int main()
{
    string num1, num2;

    cin >> num1;
    cin >> num2;

    cout << sum2(num1, num2) << endl;
    // cout << sub2(num1, num2) << endl;
}