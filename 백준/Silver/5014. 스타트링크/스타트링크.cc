#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int F;
int S;
int G;
int U;
int D;
int vis[1000001];
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    fill(vis, vis + 1000001, -1);
    Q.push(S);
    vis[S] = 0;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int next : {cur - D, cur + U})
        {
            if (next <= 0 || next > F)
                continue;
            if (vis[next] != -1)
                continue;
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
    }
    if (vis[G] != -1)
        cout << vis[G];
    else
        cout << "use the stairs";
    return 0;
}