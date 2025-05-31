#include <bits/stdc++.h>
using namespace std;

int K;
int arr[13];
int digit[13];
bool isused[13];

void func(int num)
{
    if (num == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < K; i++)
    {
        if (!isused[i] && arr[num - 1] < digit[i])
        {
            arr[num] = digit[i];
            isused[i] = 1;
            func(num + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    K = 1;
    while (K != 0)
    {
        cin >> K;
        for (int i = 0; i < K; i++)
            cin >> digit[i];
        func(0);
        cout << "\n";
    }
    return 0;
}