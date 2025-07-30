#include <bits/stdc++.h>
using namespace std;

int N;
int num;
int cnt;

bool isPrimeNumber(int num)
{
    if (num == 1)
        return false;
    else if (num == 2)
        return true;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (isPrimeNumber(num))
            cnt++;
    }
    cout << cnt;
    return 0;
}