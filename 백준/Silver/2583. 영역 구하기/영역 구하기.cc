#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int M;
int K;
int startx;
int starty;
int endx;
int endy;
int board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> V;
queue<pair<int, int>> Q;

int bfs(int x, int y)
{
    int cnt;
    cnt = 0;
    Q.push({x, y});
    vis[x][y] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 1 || vis[nx][ny])
                continue;
            Q.push({nx, ny});
            vis[nx][ny] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    int num;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    while (K--)
    {
        cin >> startx >> starty >> endx >> endy;
        for (int i = starty; i < endy; i++)
        {
            for (int j = startx; j < endx; j++)
                board[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 && vis[i][j] == 0)
            {
                num = bfs(i, j);
                V.push_back(num + 1);
                // cout << i << ", " << j << "\n";
            }
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << "\n";
    for (auto p = V.begin(); p != V.end(); p++)
        cout << *p << " ";

    /*
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                cout << vis[i][j];
            cout << "\n";
        }
    */
    return 0;
}