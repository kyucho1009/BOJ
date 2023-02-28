#include <iostream>
using namespace std;

int main()
{
    int num = 0;

    cin >> num;
    for (int i = 0; i< num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (num * 2) - (i * 2) - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}