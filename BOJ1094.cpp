#include <bits/stdc++.h>
using namespace std;

int X;
int cnt;
int sum;
int branch;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> X;
    cnt = 1;
    sum = 64;
    branch = 64;
    while (true)
    {
        if (sum == X)
            break;
        if (sum - branch / 2 >= X)
            sum -= (branch / 2);
        else
            cnt++;
        branch /= 2;
    }
    cout << cnt;
}