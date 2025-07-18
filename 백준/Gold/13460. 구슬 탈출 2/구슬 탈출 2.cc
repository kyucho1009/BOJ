#include <bits/stdc++.h>
using namespace std;

struct INFO
{
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};

INFO start;

int N;
int M;
char board[10][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    int vis[10][10][10][10] = {
        0,
    };
    queue<INFO> Q;
    Q.push(start);
    vis[start.rx][start.ry][start.bx][start.by] = 1;
    int ret;
    ret = -1;
    while (!Q.empty())
    {
        INFO cur = Q.front();
        Q.pop();
        if (cur.cnt > 10)
            break;
        if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O')
        {
            ret = cur.cnt;
            break;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nrx = cur.rx;
            int nry = cur.ry;
            int nbx = cur.bx;
            int nby = cur.by;
            while (1)
            {
                if (board[nrx][nry] != '#' && board[nrx][nry] != 'O')
                {
                    nrx += dx[dir];
                    nry += dy[dir];
                }
                else
                {
                    if (board[nrx][nry] == '#')
                    {
                        nrx -= dx[dir];
                        nry -= dy[dir];
                    }
                    break;
                }
            }
            while (1)
            {
                if (board[nbx][nby] != '#' && board[nbx][nby] != 'O')
                {
                    nbx += dx[dir];
                    nby += dy[dir];
                }
                else
                {
                    if (board[nbx][nby] == '#')
                    {
                        nbx -= dx[dir];
                        nby -= dy[dir];
                    }
                    break;
                }
            }
            if (nrx == nbx && nry == nby)
            {

                if (board[nrx][nry] != 'O')
                {
                    int rdist = abs(nrx - cur.rx) + abs(nry - cur.ry);
                    int bdist = abs(nbx - cur.bx) + abs(nby - cur.by);
                    if (rdist > bdist)
                    {
                        nrx -= dx[dir];
                        nry -= dy[dir];
                    }
                    else
                    {
                        nbx -= dx[dir];
                        nby -= dy[dir];
                    }
                }
            }
            if (vis[nrx][nry][nbx][nby] == 0)
            {
                vis[nrx][nry][nbx][nby] = 1;
                INFO next;
                next.rx = nrx;
                next.ry = nry;
                next.bx = nbx;
                next.by = nby;
                next.cnt = cur.cnt + 1;
                Q.push(next);
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                start.rx = i;
                start.ry = j;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'B')
            {
                start.bx = i;
                start.by = j;
            }
        }
    }
    start.cnt = 0;
    int ret = bfs();
    cout << ret;
    return 0;
}