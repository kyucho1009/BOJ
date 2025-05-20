#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
bool isused1[14];
bool isused2[27];
bool isused3[27];
bool board[14][14];

void func(int num)
{
    if (num == N)
        cnt++;
    for (int i = 0; i < N; i++)
    {
        if (!isused1[i] && !isused2[num + i] && !isused3[num - i + N - 1])
        {
            board[num][i] = 1;
            isused1[i] = 1;
            isused2[num + i] = 1;
            isused3[num - i + N - 1] = 1;
            func(num + 1);
            board[num][i] = 0;
            isused1[i] = 0;
            isused2[num + i] = 0;
            isused3[num - i + N - 1] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func(0);
    cout << cnt;
    return 0;
}
// 1 + (N - 1) * 2 = 2N - 1