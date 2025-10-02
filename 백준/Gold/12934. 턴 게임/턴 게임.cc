#include <bits/stdc++.h>
using namespace std;

long long x;
long long y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    long long sum;
    sum = x + y;
    long long st;
    long long temp;
    st = 1;
    temp = 0;
    while (true)
    {
        if (sum <= temp)
            break;
        temp += st;
        st++;
    }
    st--;
    if (sum != temp)
    {
        cout << -1;
        return 0;
    }
    long cnt;
    cnt = 0;
    for (long long i = st; i > 0; i--)
    {
        if (x >= i)
        {
            x -= i;
            cnt++;
        }
        else
            continue;
    }
    cout << cnt;
    return 0;
}