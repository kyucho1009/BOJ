#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;                             // 가로 크기
int M;                             // 세로 크기
int ans;                           // 정답
int cnt;                           // 늘어난 오염 구역 크기
int blank;                         // 빈칸 개수
int board[10][10];                 // 연구소 지도
queue<pair<int, int>> virus;       // 오염구역
vector<pair<int, int>> blank_cell; // 빈칸 좌표
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    queue<pair<int, int>> Q;
    bool vis[10][10] = {};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 2)
                Q.push({i, j});
        }
    }
    int cnt = 0;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        cnt++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 0)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                blank_cell.push_back({i, j});
                blank++;
            }
            else if (board[i][j] == 2)
                virus.push({i, j});
        }
    }
    for (int i = 0; i < blank_cell.size(); i++)
    {
        board[blank_cell[i].X][blank_cell[i].Y] = 1;
        for (int j = i + 1; j < blank_cell.size(); j++)
        {
            board[blank_cell[j].X][blank_cell[j].Y] = 1;
            for (int k = j + 1; k < blank_cell.size(); k++)
            {
                board[blank_cell[k].X][blank_cell[k].Y] = 1;

                int tmp = bfs();
                ans = max(blank - 3 - tmp + (int)virus.size(), ans);
                board[blank_cell[k].X][blank_cell[k].Y] = 0;
            }
            board[blank_cell[j].X][blank_cell[j].Y] = 0;
        }
        board[blank_cell[i].X][blank_cell[i].Y] = 0;
    }
    cout << ans;
}