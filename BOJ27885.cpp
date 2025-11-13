#include <bits/stdc++.h>
using namespace std;

int c;
int h;
int ans;
string T;
int arr1[601];
int arr2[601];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ans = 86400;
    cin >> c >> h;
    ans -= (c * 40);
    ans -= (h * 40);
    for (int i = 0; i < c; i++)
    {
        int t;
        cin >> T;
        t = (T[0] * 10 + T[1]) * 3600 + (T[3] * 10 + T[4]) * 60 + (T[6] * 10 + T[7]);
        arr1[i] = t;
    }
    for (int i = 0; i < h; i++)
    {

        int t;
        cin >> T;
        t = (T[0] * 10 + T[1]) * 3600 + (T[3] * 10 + T[4]) * 60 + (T[6] * 10 + T[7]);
        arr2[i] = t;
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (abs(arr1[i] - arr2[j]) >= 40)
                continue;
            ans += (40 - abs(arr1[i] - arr2[j]));
        }
    }
    cout << ans;
    return 0;
}