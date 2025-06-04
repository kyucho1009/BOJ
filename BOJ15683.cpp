#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int ans = 65;
int board[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cctv;

void check_vison(int x, int y, int dir)
{
    dir %= 4;
    while (1)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            return;
        if (board[nx][ny] == 6)
            return;
        if (board[nx][ny] != 0)
            continue;
        board[nx][ny] = -1;
    }
}

void fetch_board(int num)
{
    if (num == cctv.size())
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == 0)
                    cnt++;
        ans = min(ans, cnt);
        return;
    }

    int tmp[8][8];

    for (int dir = 0; dir < 4; dir++)
    {
        pair<int, int> cur = cctv[num];
        // 이전 상태 저장
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                tmp[i][j] = board[i][j];
        if (board[cur.first][cur.second] == 1)
        {
            check_vison(cur.first, cur.second, dir);
        }
        else if (board[cur.first][cur.second] == 2)
        {
            check_vison(cur.first, cur.second, dir);
            check_vison(cur.first, cur.second, dir + 2);
        }
        else if (board[cur.first][cur.second] == 3)
        {
            check_vison(cur.first, cur.second, dir);
            check_vison(cur.first, cur.second, dir + 1);
        }
        else if (board[cur.first][cur.second] == 4)
        {
            check_vison(cur.first, cur.second, dir);
            check_vison(cur.first, cur.second, dir + 1);
            check_vison(cur.first, cur.second, dir + 2);
        }
        else if (board[cur.first][cur.second] == 5)
        {
            check_vison(cur.first, cur.second, dir);
            check_vison(cur.first, cur.second, dir + 1);
            check_vison(cur.first, cur.second, dir + 2);
            check_vison(cur.first, cur.second, dir + 3);
        }
        // 다음 cctv 조사
        fetch_board(num + 1);
        // 이전 상태로 복원
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board[i][j] = tmp[i][j];
    }
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
            if (board[i][j] != 0 && board[i][j] != 6)
                cctv.push_back({i, j});
        }
    }
    fetch_board(0);
    cout << ans;
}