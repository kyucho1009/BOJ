#include <bits/stdc++.h>
using namespace std;

int N;
int board[1024][1024];

int func(int x, int y, int n)
{
    int arr[4];
    vector<int> V;
    if (n == 1) // 해당 조건이 없으면 N이 1일때 무한루프
        return board[0][0];
    if (n == 2) // N이 2일때 2번쨰로 작은 수 반환
    {
        for (int i = x; i < x + n; i++)
            for (int j = y; j < y + n; j++)
                V.push_back(board[i][j]);
        sort(V.begin(), V.end());
        return V[1];
    }
    else // N이 2가 될때까지 자르기
    {
        arr[0] = func(x, y, n / 2);
        arr[1] = func(x + n / 2, y, n / 2);
        arr[2] = func(x, y + n / 2, n / 2);
        arr[3] = func(x + n / 2, y + n / 2, n / 2);
        sort(arr, arr + 4);
        return arr[1]; // 반환 받은 수들 중 2번째로 작은 수 반환
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    int num;
    num = func(0, 0, N);
    cout << num;
    return 0;
}