#include <bits/stdc++.h>
using namespace std;

int N;       // 수의 개수
int mx;      // 최댓값
int mn;      // 최솟값
int num[11]; // 숫자
int oper[4]; // 연산자

void func(int depth, int ans)
{
    if (depth == N)
    {
        mx = max(mx, ans);
        mn = min(mn, ans);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (oper[i] == 0)
            continue;
        oper[i]--;
        if (i == 0)
            func(depth + 1, ans + num[depth]);
        else if (i == 1)
            func(depth + 1, ans - num[depth]);
        else if (i == 2)
            func(depth + 1, ans * num[depth]);
        else
            func(depth + 1, ans / num[depth]);
        oper[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    mx = -2147483648;
    mn = 2147483647;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];
    func(1, num[0]);
    cout << mx << "\n"
         << mn;
    return 0;
}