#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int TestCase;
int Length;
int StartX;
int StartY;
int EndX;
int EndY;
int vis[300][300];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
queue <pair<int, int>> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TestCase;
	while (TestCase--)
	{
		cin >> Length;
		for (int i = 0; i < Length; i++)
			fill(vis[i], vis[i] + Length, -1);
		cin >> StartX >> StartY;
		vis[StartX][StartY] = 0;
		Q.push({StartX, StartY});
		cin >> EndX >> EndY;
		while (!Q.empty())
		{
			pair <int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= Length || ny < 0 || ny >= Length)
					continue;
				if (vis[nx][ny] >= 0)
					continue;
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
				Q.push({nx, ny});
			}
		}
		cout << vis[EndX][EndY] << "\n";
	}
	return 0;
}