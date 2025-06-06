#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int K;
int cnt;
int tmp[10][10];
int board[40][40];
int sticker[10][10];
pair<int, int> stickerSize;

bool pastable(int X, int Y)
{
    if (X + stickerSize.first > N || Y + stickerSize.second > M)
        return false;
    for (int i = 0; i < stickerSize.first; i++)
        for (int j = 0; j < stickerSize.second; j++)
            if (sticker[i][j] == 1 && board[i + X][j + Y] == 1)
                return false;
    return true;
}

void paste(int X, int Y)
{
    for (int i = 0; i < stickerSize.first; i++)
        for (int j = 0; j < stickerSize.second; j++)
            if (sticker[i][j] == 1)
                board[i + X][j + Y] = 1;
}

void rotate()
{
    for (int i = 0; i < stickerSize.first; i++)
        for (int j = 0; j < stickerSize.second; j++)
            tmp[j][stickerSize.first - i - 1] = sticker[i][j];

    swap(stickerSize.first, stickerSize.second);
    for (int i = 0; i < stickerSize.first; i++)
        for (int j = 0; j < stickerSize.second; j++)
            sticker[i][j] = tmp[i][j];
}

void ans()
{
    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 0; i <= N - stickerSize.first; i++)
            for (int j = 0; j <= M - stickerSize.second; j++)
                if (pastable(i, j))
                {
                    paste(i, j);
                    return;
                }
        rotate();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    while (K--)
    {
        cin >> stickerSize.first >> stickerSize.second;
        for (int i = 0; i < 10; i++)
            memset(sticker[i], 0, sizeof(sticker[i]));
        for (int i = 0; i < 10; i++)
            memset(tmp[i], 0, sizeof(tmp[i]));
        for (int i = 0; i < stickerSize.first; i++)
            for (int j = 0; j < stickerSize.second; j++)
                cin >> sticker[i][j];
        ans();
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 1)
                cnt++;
    cout << cnt;
}