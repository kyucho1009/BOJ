#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t;
int w;
int h;
char c;
bool escape;
int board[1002][1002];
int vis1[1002][1002];
int vis2[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> w >> h;
		escape = false;
		queue <pair<int, int>> Q1;
		queue <pair<int, int>> Q2;
		for (int i = 0; i < h; i++)
		{
			fill(vis1[i], vis1[i] + w, 0);
			fill(vis2[i], vis2[i] + w, 0);
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> c;
				if (c == '#')
					board[i][j] = -1;
				else if (c == '*')
				{
					Q1.push({i, j});
					vis1[i][j] = 1;
				}
				else if (c == '@')
				{
					Q2.push({i, j});
					vis2[i][j] = 1;
				}
				else
					board[i][j] = 0;
			}
		}
		while (!Q1.empty())
		{
			pair <int, int> cur = Q1.front();
			Q1.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (vis1[nx][ny] != 0 || board[nx][ny] == -1)
					continue;
				vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
				Q1.push({nx, ny});
			}
		}
		while ((!Q2.empty()) && (!escape))
		{
			pair <int, int> cur = Q2.front();
			Q2.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{	
					cout << vis2[cur.X][cur.Y] << "\n";
					escape = true;
					break;
				}
				if (board[nx][ny] == -1)
					continue;
				if (vis2[nx][ny] != 0)
					continue;
				if (vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1 && vis1[nx][ny] != 0)
					continue;
				vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
				Q2.push({nx, ny});
			}
		}
		if (!escape)
			cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}