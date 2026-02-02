#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int DP[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    DP[0][0] = 1;
    DP[1][0] = 1;
    DP[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
                DP[i][j] = 1;
            else
                DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % 10007;
        }
    }
    cout << DP[N][K];
}