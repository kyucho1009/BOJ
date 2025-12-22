#include <bits/stdc++.h>
using namespace std;

int N;
int H;
int height[101];
long long dp[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;
    for (int i = 0; i < N; i++)
        cin >> height[i];
    dp[0] = 1;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cur = height[j];
            if (i - cur >= 0)
            {
                dp[i] += (dp[i - cur] % 1000000007);
                dp[i] %= 1000000007;
            }
        }
    }
    cout << dp[H];
    return 0;
}