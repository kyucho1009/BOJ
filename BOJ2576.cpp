#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int min = 0;
    int sum = 0;
    int arr[7] = {0};

    for(int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    for(int i = 0; i < 7; i++)
    {
        if (arr[i] % 2 == 1)
            sum += arr[i];
        else
            continue;
    }
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] % 2 == 1)
        {
            min = arr[i];
            break;
        }
    }
    if (min == 0)
        cout << -1;
    else
    {
        cout << sum << "\n";
        cout << min;
    }

    return 0;
}