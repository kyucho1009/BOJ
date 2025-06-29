#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int m;
bool vis[1000][1000];
int board[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2) // 시작점 잡기
                start = {i, j};
            board[i][j] += -2; // 보드 재구성 (2 -> 0, 1 -> -1, 0 -> -2) 원래 갈 수 있는 땅에 도달 못한 부분을 -1로 재처리하는 과정 생략 가능
        }
    }
    // BFS 시작
    queue<pair<int, int>> Q;
    vis[start.X][start.Y] = 1;
    Q.push(start);
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == -2 || vis[nx][ny])
                continue;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == -2)
                cout << 0 << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}