#include <bits/stdc++.h>
using namespace std;

int N;
int R;
int G;
int B;
int DP[3][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    DP[0][0] = 0;
    DP[1][0] = 0;
    DP[2][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> R >> G >> B;
        for (int j = 0; j < 3; j++)
        {
            int temp;
            if (j == 0)
                temp = min(R + DP[1][i - 1], R + DP[2][i - 1]);
            else if (j == 1)
                temp = min(G + DP[0][i - 1], G + DP[2][i - 1]);
            else
                temp = min(B + DP[0][i - 1], B + DP[1][i - 1]);
            DP[j][i] = temp;
        }
    }
    cout << min(DP[0][N], min(DP[1][N], DP[2][N]));
    return 0;
}