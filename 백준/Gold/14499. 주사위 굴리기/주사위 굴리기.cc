#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int X;
int Y;
int K;
int order;
int dice[6];
int board[20][20];

void move(int dir)
{
    int temp = dice[2];
    if (dir == 1)
    {
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
        Y++;
    }
    else if (dir == 2)
    {
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
        Y--;
    }
    else if (dir == 3)
    {
        dice[2] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[0];
        dice[0] = temp;
        X--;
    }
    else
    {
        dice[2] = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
        X++;
    }
    if (board[X][Y] != 0)
    {
        dice[5] = board[X][Y];
        board[X][Y] = 0;
    }
    else
        board[X][Y] = dice[5];

    cout << dice[2] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X >> Y >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    for (int i = 0; i < K; i++)
    {
        cin >> order;
        if (order == 1 && Y == M - 1)
            continue;
        if (order == 2 && Y == 0)
            continue;
        if (order == 3 && X == 0)
            continue;
        if (order == 4 && X == N - 1)
            continue;
        move(order);
    }
    return 0;
}