#include <iostream>
#include <string>

using namespace std;

string sum2(string num1, string num2);
string sub2(string num1, string num2);

int main()
{
    string num1, num2;

    cout << "Input first  number >> ";
    cin >> num1;
    cout << "Input second number >> ";
    cin >> num2;

    cout << "\n\n\n<Result>\n"
         << endl;
    cout << "Summation   Result >> " << sum2(num1, num2) << endl;
    cout << "Subtraction Result >> " << sub2(num1, num2) << endl;
}