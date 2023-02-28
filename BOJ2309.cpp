#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int sum = 0;
    int index1 = 0;
    int index2 = 1;
    int arr[9] = {0};

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                index1 = i;
                index2 = j;
                break;
            }
        }
        if (sum - arr[index1] - arr[index2] == 100)
            break;
    }
    arr[index1] = 0;
    arr[index2] = 0;
    sort(arr, arr +9);
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == 0)
            continue;
        cout << arr[i] << "\n";
    }
}