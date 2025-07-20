#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int H;
bool ladder[32][12];
vector<pair<int, int>> pos;

bool check()
{
    for (int i = 1; i <= N; i++)
    {
        int col = i;
        for (int j = 1; j <= H; j++)
        {
            if (ladder[j][col])
                col++;
            else if (ladder[j][col - 1])
                col--;
        }
        if (col != i)
            return false;
    }
    return true;
}

void dfs(int maxDepth, int cnt)
{
    if (maxDepth == cnt)
    {
        if (check())
        {
            cout << maxDepth;
            exit(0);
        }
        return;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            if (ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1])
                continue;
            ladder[j][i] = 1;
            dfs(maxDepth, cnt + 1);
            ladder[j][i] = 0;
            while (!ladder[j][i - 1] && !ladder[j][i + 1])
                j++;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> H;
    while (M--)
    {
        int a;
        int b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1])
                continue;
            pos.push_back({i, j});
        }
    }

    if (check())
    {
        cout << 0;
        return 0;
    }

    int ans = 2147483647;
    int sz = pos.size();
    for (int i = 0; i < sz; i++)
    {
        ladder[pos[i].first][pos[i].second] = 1;
        if (check())
            ans = min(ans, 1);
        for (int j = i + 1; j < sz; j++)
        {
            ladder[pos[j].first][pos[j].second] = 1;
            if (check())
                ans = min(ans, 2);
            for (int k = j + 1; k < sz; k++)
            {
                ladder[pos[k].first][pos[k].second] = 1;
                if (check())
                    ans = min(ans, 3);
                ladder[pos[k].first][pos[k].second] = 0;
            }
            ladder[pos[j].first][pos[j].second] = 0;
        }
        ladder[pos[i].first][pos[i].second] = 0;
    }
    if (ans == 2147483647)
        ans = -1;
    cout << ans;

    return 0;
}