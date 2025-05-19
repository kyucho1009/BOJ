#include <bits/stdc++.h>
using namespace std;

int num;
int blue;
int white;
int board[128][128];

bool issame(int x, int y, int n) // 종이의 숫자들이 같은지 확인
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[x][y] != board[i][j])
                return false;
        }
    }
    return true;
}

void func(int x, int y, int n)
{
    if (issame(x, y, n))
    {
        if (board[x][y] == 0)
            white++;
        else
            blue++;
    }
    else
    {
        func(x, y, n / 2);
        func(x + n / 2, y, n / 2);
        func(x, y + n / 2, n / 2);
        func(x + n / 2, y + n / 2, n / 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    blue = 0;
    white = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> board[i][j];
    func(0, 0, num);
    cout << white << "\n";
    cout << blue;
    return 0;
}