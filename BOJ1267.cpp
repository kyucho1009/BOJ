#include <iostream>
using namespace std;

int main()
{
    int Y = 0;
    int M = 0;
    int num;
    int *arr;

    cin >> num;
    arr = new int[num];
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
        Y += (arr[i] / 30 + 1) * 10;
        M += (arr[i] / 60 + 1) * 15;
    }
    if (Y < M)
        cout << "Y" << " " << Y;
    else if (M < Y)
        cout << "M" << " " << M;
    else
        cout << "Y" << " " << "M" << " " << Y;

    return 0;
}