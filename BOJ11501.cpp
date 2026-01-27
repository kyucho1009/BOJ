#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int temp[1000001];
int price[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        long long ans;
        ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> price[i];
        int mx = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            mx = max(mx, price[i]);
            temp[i] = mx;
        }
        for (int i = 0; i < N; i++)
            ans += temp[i] - price[i];
        cout << ans << "\n";
    }
    return 0;
}
/*
1
11
8 6 7 10 5 6 9 1 2 3 4
*/