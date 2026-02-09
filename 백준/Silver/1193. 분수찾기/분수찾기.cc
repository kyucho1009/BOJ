#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int num = 1;
    while (true)
    {
        if (N - num > 0)
            N -= num;
        else
            break;
        num++;
    }
    if (num % 2 == 0)
        cout << N << "/" << (num - N + 1);
    else
        cout << (num - N + 1) << "/" << N;
    return 0;
}