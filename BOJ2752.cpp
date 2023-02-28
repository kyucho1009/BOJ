#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    int arr[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    sort(arr, arr+3);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}