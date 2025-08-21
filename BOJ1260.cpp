#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int V;
bool vis[1001];
bool board[1001][1001];
queue<int> Q;

void dfs(int node)
{
    vis[node] = 1;
    cout << node << " ";
    for (int i = 1; i <= N; i++)
        if (board[node][i] && vis[i] == 0)
            dfs(i);
}

void bfs()
{
    Q.push(V);
    vis[V] = 1;
    cout << V << " ";
    while (!Q.empty())
    {
        int cur;
        cur = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (board[cur][i] && vis[i] == 0)
            {
                Q.push(i);
                vis[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> V;
    int a;
    int b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = 1;
    }
    dfs(V);
    cout << "\n";
    for (int i = 0; i <= N; i++)
        vis[i] = 0;
    bfs();
    return 0;
}