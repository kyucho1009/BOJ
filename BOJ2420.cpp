#include <iostream>
using namespace std;

int main()
{
    int famous1, famous2;

    cin >> famous1 >> famous2;
    if (famous1 > famous2)
        cout << (long)famous1 - famous2;
    else
        cout << (long)famous2 - famous1;
    return 0;
}