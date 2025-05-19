#include <bits/stdc++.h>
using namespace std;

int num;
string board[64];

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
        if (board[x][y] == '0')
            cout << 0;
        else
            cout << 1;
    }
    else
    {
        cout << "(";
        func(x, y, n / 2);
        func(x, y + n / 2, n / 2);
        func(x + n / 2, y, n / 2);
        func(x + n / 2, y + n / 2, n / 2);
        cout << ")";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> board[i];
    func(0, 0, num);
    return 0;
}