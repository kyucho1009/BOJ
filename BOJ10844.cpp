#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
int DP[10][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i < 10; i++)
        DP[i][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                DP[j][i] = DP[j + 1][i - 1];
            else if (j == 9)
                DP[j][i] = DP[j - 1][i - 1];
            else
                DP[j][i] = DP[j - 1][i - 1] + DP[j + 1][i - 1];
            DP[j][i] %= 1000000000;
        }
    }
    for (int i = 0; i < 10; i++)
        ans = (ans + DP[i][N]) % 1000000000;
    cout << ans;
    return 0;
}