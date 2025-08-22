#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int w;
int h;
int cnt;
int board[51][51];
bool vis[51][51];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> Q;
    vis[x][y] = 1;
    Q.push({x, y});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cnt = 0;
        cin >> w >> h;
        if (w + h == 0)
            break;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> board[i][j];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == 1 && vis[i][j] == 0)
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                vis[i][j] = 0;
        cout << cnt << "\n";
    }
    return 0;
}