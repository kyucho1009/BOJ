#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
bool vis[100][100];
int board[100][100];
int height[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;
vector<int> V;

int bfs(int h)
{
    int cnt;
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        fill(vis[i], vis[i] + N, 0);
        fill(board[i], board[i] + N, 0);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (height[i][j] <= h)
                board[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1 || vis[i][j])
                continue;
            cnt++;
            Q.push({i, j});
            vis[i][j] = 1;
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
                    if (board[nx][ny] == 1 || vis[nx][ny])
                        continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
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
    {
        for (int j = 0; j < N; j++)
            cin >> height[i][j];
    }
    /*
    int num;
    num = bfs(3);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << num;
    */
    for (int i = 1; i < 101; i++)
        V.push_back(bfs(i));
    cout << *max_element(V.begin(), V.end());
    return 0;
}