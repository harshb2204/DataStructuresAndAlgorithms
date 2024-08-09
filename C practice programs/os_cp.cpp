#include <iostream>
#include <fstream>
using namespace std;

class OS
{
private:
    char Memory[100][4]; // Memory
    unsigned char R[4];  // Register
    unsigned char IR[4]; // Instruction Registers
    unsigned int IC;     // Instruction counter
    bool C;              // Toggle Value
    int SI;              // Interrupt
    char buffer[200];    // Buffer
    fstream inputfile;

public:
    void INIT();
    void LOAD();
};

void OS ::INIT()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 4; j++)
            Memory[i][j] = ' ';

    for (int i = 0; i < 4; i++)
    {
        R[i] = ' ';
        IR[i] = ' ';
    }

    IC = ;
    C = false;
    SI = 0;
}

void OS ::LOAD()
{
    cout << "Reading Data..." << endl;
    int x = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 4; j++) // clear buffer
            Memory[i][j] = ' ';
    do
    {

        for (int i = 0; i <= 100; i++) // clear buffer
            buffer[i] = ' ';

        inputfile.getline(buffer, 42);

        if (buffer[0] == '$' && buffer[1] == 'A' && buffer[2] == 'M' && buffer[3] == 'J')
        {
            INIT();
        }
        else if (buffer[0] == '$' && buffer[1] == 'D' && buffer[2] == 'T' && buffer[3] == 'A')
        {
            // Start();
        }
        else if (buffer[0] == '$' && buffer[1] == 'E' && buffer[2] == 'N' && buffer[3] == 'D')
        {
            x = 0;
            for (int i = 0; i < 100; i++)
            {
                cout << "M[" << i << "]\t";

                for (int j = 0; j < 4; j++)
                {
                    cout << Memory[i][j];
                }
                cout << endl;
                if (i % 10 == 9)
                    cout << endl;
            }
            cin.get();
            continue;
        }
        else
        {
            int k = 0;

            int limit = x + 10;
            for (; x < limit; ++x)
            {
                for (int j = 0; j < 4; ++j)
                {
                    Memory[x][j] = buffer[k];
                    k++;
                }
                if (buffer[k] == ' ' || buffer[k] == '\n')
                {
                    break;
                }
            }
        }
    } while (!inputfile.eof());
}

int main()
{
    OS os;
    os.inputfile.open("input.txt", ios::in);

    if (!os.inputfile)
        cout << "File doesn't exist" << endl;
    else
        cout << "File Exist" << endl;

    os.LOAD();
    os.inputfile.close();
    return 0;
}
