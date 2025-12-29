#include <bits/stdc++.h>
using namespace std;

int N;
long long DP[2][91];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    DP[0][1] = 0;
    DP[1][1] = 1;
    DP[0][2] = 1;
    DP[1][2] = 0;
    for (int i = 3; i <= N; i++)
    {
        DP[0][i] = DP[0][i - 1] + DP[1][i - 1];
        DP[1][i] = DP[0][i - 1];
    }
    cout << DP[0][N] + DP[1][N];
    return 0;
}