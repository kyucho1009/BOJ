#include <bits/stdc++.h>
using namespace std;

int T;
int num;
long long DP[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    for (int i = 6; i < 101; i++)
        DP[i] = DP[i - 1] + DP[i - 5];
    while (T--)
    {
        cin >> num;
        cout << DP[num] << "\n";
    }
    return 0;
}