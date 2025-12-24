#include <bits/stdc++.h>
using namespace std;

int n;
int DP[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= n; i++)
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    cout << DP[n];
    return 0;
}