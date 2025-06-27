#include <bits/stdc++.h>
using namespace std;

int ans;
int pos;
string isbn;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> isbn;
    bool iseven;
    for (int i = 0; i < 13; i++)
    {
        if (isbn[i] == '*')
            iseven = i % 2;
        else
            ans += (isbn[i] - '0') * (pow(3, i % 2));
    }
    ans %= 10;
    if (iseven)
    {
        for (int i = 0; i < 10; i++)
        {
            if ((ans + i * 3) % 10 == 0)
            {
                cout << i;
                break;
            }
        }
    }
    else
        cout << (10 - ans) % 10;
    return 0;
}