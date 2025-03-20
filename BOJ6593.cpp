#include <bits/stdc++.h>
using namespace std;

int L;
int R;
int C;
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            break;
        int vis[30][30][30];
        char board[30][30][30];
        tuple<int, int, int> ans;
        queue<tuple<int, int, int>> Q;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
                fill(vis[i][j], vis[i][j] + C, 0);
        }
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S')
                        Q.push({i, j, k});
                    else if (board[i][j][k] == '#')
                        vis[i][j][k] = -1;
                    else if (board[i][j][k] == 'E')
                        ans = {i, j, k};
                }
            }
        }
        while (!Q.empty())
        {
            tuple<int, int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 6; dir++)
            {
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];
                if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)
                    continue;
                if (vis[nx][ny][nz] > 0 || board[nx][ny][nz] == '#')
                    continue;
                vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({nx, ny, nz});
            }
        }
        if (vis[get<0>(ans)][get<1>(ans)][get<2>(ans)] != 0)
            cout << "Escaped in " << vis[get<0>(ans)][get<1>(ans)][get<2>(ans)] << "minute(s).\n";
        else
            cout << "Trapped!\n";
    }
    return 0;
}