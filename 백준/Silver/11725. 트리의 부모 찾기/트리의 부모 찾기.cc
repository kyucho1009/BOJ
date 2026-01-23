#include <bits/stdc++.h>
using namespace std;

int N;
int a;
int b;
int ans[100001];
bool vis[100001];
vector<vector<int>> T(100001);

void dfs(int node)
{
    vis[node] = 1;
    for (int i = 0; i < T[node].size(); i++)
    {
        int nx = T[node][i];
        if (!vis[nx])
        {
            ans[nx] = node;
            dfs(nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
        cout << ans[i] << "\n";
    return 0;
}