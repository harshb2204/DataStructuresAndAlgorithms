#include <iostream>
using namespace std;

int main()
{
    int codeWord[7];
    cout << "Enter code word : ";
    for (int i = 0; i < 7; i++)
    {
        cin >> codeWord[i];
    }

    int firstBit = codeWord[0];
    int secondBit = codeWord[1];
    int fourthBit = codeWord[3];

    int p1 = codeWord[2] + codeWord[4] + codeWord[6];
    int p2 = codeWord[2] + codeWord[5] + codeWord[6];
    int p4 = codeWord[4] + codeWord[5] + codeWord[6];

    int errorBit = 0;
    if (p1 % 2 != 0 && firstBit == 0)
    {
        errorBit += 1;
    }

    if (p2 % 2 != 0 && secondBit == 0)
    {
        errorBit += 2;
    }

    if (p4 % 2 != 0 && fourthBit == 0)
    {
        errorBit += 4;
    }

    cout << "Error occurred in bit " << errorBit << endl;

    codeWord[errorBit - 1] = 0;

    cout << "Correct code word is : ";
    for (int i = 0; i < 7; i++)
    {
        cout << codeWord[i] << " ";
    }

    return 0;
}
