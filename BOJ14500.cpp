#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int ans;
int tetromino[4][4];
int board[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3])); // ㅡ
            ans = max(ans, (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j])); // ㅣ

            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1])); // ㅁ

            ans = max(ans, (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1]));         // L
            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j]));             //
            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]));     // 7
            ans = max(ans, (board[i][j + 2] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2])); // ㅢ

            ans = max(ans, (board[i + 2][j] + board[i + 2][j + 1] + board[i + 1][j + 1] + board[i][j + 1])); //
            ans = max(ans, (board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]));     // ㄴ
            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j]));             //
            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2]));         // ㄱ

            ans = max(ans, (board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]));
            ans = max(ans, (board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i][j + 2]));

            ans = max(ans, (board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j] + board[i + 2][j]));
            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2]));

            ans = max(ans, (board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i][j + 2]));
            ans = max(ans, (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]));
            ans = max(ans, (board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]));
            ans = max(ans, (board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 1][j]));
        }
    }
    cout << ans;
}