/*
1. 숫자 확인
2. 자르기
3. 반복
*/
#include <bits/stdc++.h>
using namespace std;

int plusOne;
int zero;
int minusOne;
int num;
int board[2187][2187];

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
        if (board[x][y] == -1)
            minusOne++;
        else if (board[x][y] == 0)
            zero++;
        else
            plusOne++;
    }
    else
    {
        func(x, y, n / 3);
        func(x, y + n / 3, n / 3);
        func(x, y + n / 3 + n / 3, n / 3);
        func(x + n / 3, y, n / 3);
        func(x + n / 3, y + n / 3, n / 3);
        func(x + n / 3, y + n / 3 + n / 3, n / 3);
        func(x + 2 * n / 3, y, n / 3);
        func(x + 2 * n / 3, y + n / 3, n / 3);
        func(x + n / 3 + n / 3, y + n / 3 + n / 3, n / 3);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    plusOne = 0;
    zero = 0;
    minusOne = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> board[i][j];
    func(0, 0, num);
    cout << minusOne << "\n";
    cout << zero << "\n";
    cout << plusOne;
    return 0;
}