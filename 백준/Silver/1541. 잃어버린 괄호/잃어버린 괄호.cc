#include <bits/stdc++.h>
using namespace std;

int ans;
bool isminus;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    int num;
    num = 0;
    for (auto k : str)
    {
        if (k >= '0' && k <= '9')
        {
            num *= 10;
            num += (k - 48);
        }
        else
        {
            if (!isminus)
                ans += num;
            else
                ans -= num;
            if (k == '-')
                isminus = 1;
            num = 0;
        }
    }
    if (!isminus)
        ans += num;
    else
        ans -= num;
    cout << ans;
    return 0;
}