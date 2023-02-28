#include <iostream>
#include <string>
using namespace std;

int main()
{
    int max = 0;
    int arr[9] = {0};
    string str;

    cin >> str;
    for (auto c : str)
    {
        if (c == '9')
            arr[6]++;
        else
            arr[c - '0']++;
    }
    if (arr[6] % 2 == 0)
        arr[6] /= 2;
    else
        arr[6] = arr[6] / 2 + 1;
    for (auto i : arr)
    {
        if (max < i)
            max = i;
    }
    cout << max;
    return 0;
}