#include <bits/stdc++.h>
using namespace std;

int N;
int board1[20][20];
int board2[20][20];
vector<int> V;

void rotate()
{
    int tmp[20][20];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[j][N - i - 1] = board2[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board2[i][j] = tmp[i][j];
}

void tilt(int dir)
{
    while (dir--)
        rotate();
    for (int i = 0; i < N; i++)
    {
        int idx = 0;
        int tilted[20] = {};
        for (int j = 0; j < N; j++)
        {
            if (board2[i][j] == 0)
                continue;
            if (tilted[idx] == 0)
                tilted[idx] = board2[i][j];
            else if (tilted[idx] == board2[i][j])
                tilted[idx++] *= 2;
            else
                tilted[++idx] = board2[i][j];
        }
        for (int j = 0; j < N; j++)
            board2[i][j] = tilted[j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board1[i][j];
    int mx = 0;
    for (int tmp = 0; tmp < 1024; tmp++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for (int i = 0; i < 5; i++)
        {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;
}