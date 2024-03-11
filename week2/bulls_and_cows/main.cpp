#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int generateNumber()
{

    int randNum[3] = {};
    int a = 0;

    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            randNum[i] = rand() % 9;
        }

        if (randNum[0] == randNum[1] || randNum[0] == randNum[2] || randNum[1] == randNum[2])
        {
            continue;
        }

        else
        {
            a = randNum[0] * 100 + randNum[1] * 10 + randNum[2];
            return a;
        }
    }
}
bool testAnswer(int input, int answer)
{
    int strike = 0;
    int ball = 0;
    string sanswer;
    string sinput;

    sanswer = to_string(answer);
    sinput = to_string(input);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && sinput[i] == sanswer[i])
            {
                strike++;
            }

            else if (i != j && sinput[i] == sanswer[j])
            {
                ball++;
            }
        }
    }

    if (strike == 3)
    {
        cout << strike << " strikes, " << ball << " balls" << endl;
        return true;
    }

    else
    {
        cout << strike << " strikes, " << ball << " balls" << endl;
        return false;
    }
}

int main(void)
{

    srand(time(NULL));
    int answer = generateNumber();

    int input = 0;
    int chances = 5;

    while (1)
    {
        if (chances == 0)
        {
            cout << "Game OVER! You Lose." << endl;
            return 0;
        }

        cout << chances << " chances left." << endl;
        cout << "input your guess: ";
        cin >> input;

        if (testAnswer(input, answer))
        {
            cout << "You Successed!" << endl;
            return 0;
        }

        chances--;
    }
}