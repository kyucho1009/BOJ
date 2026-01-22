#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int cnt;
bool vis[500000];
vector<vector<int>> graph(1001);

void dfs(int node)
{
    vis[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
        if (!vis[graph[node][i]])
            dfs(graph[node][i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}