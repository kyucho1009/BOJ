#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t;
int m;
int n;
int k;
int x;
int y;
int cnt;
int board[50][50];
bool vis[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue <pair<int, int>> Q;

void bfs(int x, int y)
{
	vis[x][y] = 1;
	Q.push({x, y});
	while (!Q.empty())
	{
		pair <int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] || board[nx][ny] != 1)
				continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			board[y][x] = 1;
		}
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (board[j][k] == 1 && !vis[j][k])
				{	
					bfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		for (int j = 0; j < n; j++)
		{
			fill(board[j], board[j] + m, 0);
			fill(vis[j], vis[j] + m, 0);
		}
	}
	return 0;
}