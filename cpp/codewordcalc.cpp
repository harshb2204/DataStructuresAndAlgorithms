#include <iostream>
using namespace std;

int main()
{
    int dataWord[4];
    cout << "Enter the data word : ";
    for (int i = 0; i < 4; i++)
    {
        cin >> dataWord[i];
    }
    int codeWord[7];
    codeWord[2] = dataWord[0];
    codeWord[4] = dataWord[1];
    codeWord[5] = dataWord[2];
    codeWord[6] = dataWord[3];
    if ((dataWord[1] + dataWord[2] + dataWord[3]) % 2 != 0)
    {
        codeWord[3] = 1;
    }
    else
    {
        codeWord[3] = 0;
    }

    if ((dataWord[0] + dataWord[1] + dataWord[3]) % 2 != 0)
    {
        codeWord[0] = 1;
    }
    else
    {
        codeWord[0] = 0;
    }

    if ((dataWord[0] + dataWord[2] + dataWord[3]) % 2 != 0)
    {
        codeWord[1] = 1;
    }
    else
    {
        codeWord[1] = 0;
    }
    cout << " The Code Word is => : ";
    for (int i = 0; i < 7; i++)
    {
        cout << codeWord[i] << " ";
    }
    cout << endl;
    return 0;
}
