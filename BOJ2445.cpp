#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int num = 0;

    cin >> num;
    while (i <= num)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (num - i) * 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << "\n";
        i++;
    }
    i--;
    while (--i)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (num - i) * 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}