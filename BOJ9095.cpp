#include <bits/stdc++.h>
using namespace std;

int N;
int T;
int dp[11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= N; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        cout << dp[N] << "\n";
    }
    return 0;
}