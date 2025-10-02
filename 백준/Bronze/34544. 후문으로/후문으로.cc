#include <bits/stdc++.h>
using namespace std;

int N;
int A;
int B;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ans = 1;
    while (N--)
    {
        cin >> A >> B;
        int temp;
        if (B > 0 && A < 0)
            temp = B - A - 1;
        else if (B < 0 && A > 0)
            temp = B - A + 1;
        else
            temp = B - A;
        if (temp > 0 && ans < 0 && temp >= -ans)
        {
            ans += temp;
            ans += 1;
        }
        else if (temp < 0 && ans > 0 && -temp >= ans)
        {
            ans += temp;
            ans -= 1;
        }
        else if (temp > 0)
            ans += temp;
        else if (temp < 0)
            ans += temp;
    }
    cout << ans;
    return 0;
}