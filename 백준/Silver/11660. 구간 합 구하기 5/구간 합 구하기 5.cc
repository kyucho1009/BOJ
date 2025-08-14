#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int M;
int sum[1025][1025];
int board[1025][1025];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            cin >> board[i][j];
    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            sum[i][j] = board[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    for (int i = 0; i < M; i++)
    {
        pair<int, int> st;
        pair<int, int> en;
        cin >> st.X >> st.Y >> en.X >> en.Y;
        cout << sum[en.X][en.Y] - sum[en.X][st.Y - 1] - sum[st.X - 1][en.Y] + sum[st.X - 1][st.Y - 1] << "\n";
    }
    return 0;
}