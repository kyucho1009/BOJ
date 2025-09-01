#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        if (i * 2 < 1000001)
        {
            if (dp[i * 2] != 0)
                dp[i * 2] = min(dp[i * 2], dp[i] + 1);
            else
                dp[i * 2] = dp[i] + 1;
        }
        if (i * 3 < 1000001)
        {
            if (dp[i * 3] != 0)
                dp[i * 3] = min(dp[i * 3], dp[i] + 1);
            else
                dp[i * 3] = dp[i] + 1;
        }
        if (i + 1 < 1000001)
        {
            if (dp[i + 1] != 0)
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            else
                dp[i + 1] = dp[i] + 1;
        }
    }
    cout << dp[N];
    return 0;
}

/*
아래와 같이 더 간단하게 구현 가능
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[N];
}
 */