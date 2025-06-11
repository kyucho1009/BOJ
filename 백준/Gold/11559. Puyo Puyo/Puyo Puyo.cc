#include <bits/stdc++.h>
using namespace std;

int cnt;
char board[12][6];
bool check[12][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> V;

void tilt()
{
    for (int j = 0; j < 6; j++)
    {
        int idx = 11;
        char tilted[12];
        memset(tilted, '.', sizeof(char) * 12);
        for (int i = 11; 0 <= i; i--)
        {
            if (board[i][j] == '.')
                continue;
            if (tilted[idx] == '.')
                tilted[idx] = board[i][j];
            else
                tilted[--idx] = board[i][j];
        }
        for (int i = 11; 0 <= i; i--)
            board[i][j] = tilted[i];
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> Q;
    check[x][y] = 1;
    Q.push({x, y});
    V.push_back({x, y});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                continue;
            if (board[cur.first][cur.second] != board[nx][ny] || check[nx][ny])
                continue;
            check[nx][ny] = 1;
            Q.push({nx, ny});
            V.push_back({nx, ny});
        }
    }
}

bool pop()
{
    bool chk;
    chk = true;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == '.')
                continue;
            else
            {
                bfs(i, j);
                if (V.size() >= 4)
                {
                    chk = false;
                    for (auto k : V)
                        board[k.first][k.second] = '.';
                }
                V.clear();
            }
        }
    }
    tilt();
    for (int i = 0; i < 12; i++)
        memset(check[i], 0, sizeof(bool) * 6);
    return chk;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            cin >> board[i][j];
    bool chk;
    chk = false;
    while (!chk)
    {
        chk = pop();
        if (!chk)
            cnt++;
        else
            break;
    }
    cout << cnt;
}

/*
1. 보드 생성
2. 보드 탐색 후 삭제
3. 보드 밀어주기
4. 횟수 출력
*/