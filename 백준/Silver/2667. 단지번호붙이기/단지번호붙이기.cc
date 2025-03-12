#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int num;
bool vis[25][25];
string board[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;
vector<int> V;

int bfs(int x, int y)
{
    int cnt;
    cnt = 1;
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
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] == '0' || vis[nx][ny])
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == '0' || vis[i][j] == 1)
                continue;
            V.push_back(bfs(i, j));
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << "\n";
    for (auto p = V.begin(); p != V.end(); p++)
        cout << *p << "\n";
    return 0;
}