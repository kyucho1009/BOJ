#include <bits/stdc++.h>
using namespace std;

int N;
int DP[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i <= N; i++)
        DP[i] = 2147483647;
    DP[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (i % 2 == 0)
            DP[i] = min(DP[i / 2] + 1, DP[i]);
        if (i % 3 == 0)
            DP[i] = min(DP[i / 3] + 1, DP[i]);
        DP[i] = min(DP[i - 1] + 1, DP[i]);
    }
    cout << DP[N] << "\n";
    while (N > 0)
    {
        cout << N << " ";
        if (N % 3 == 0 && DP[N / 3] == DP[N] - 1)
            N = N / 3;
        else if (N % 2 == 0 && DP[N / 2] == DP[N] - 1)
            N = N / 2;
        else
            N = N - 1;
    }
    return 0;
}