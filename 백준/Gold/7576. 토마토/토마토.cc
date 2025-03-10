#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[1000][1000];
int dist[1000][1000];
int row;
int col;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> col >> row;
	queue <pair<int, int>> Q;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				Q.push({i, j});
			if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= row || ny < 0 || ny >= col)
				continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == -1)
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	int answer = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			answer = max(answer, dist[i][j]);
		}
	}
	cout << answer;
	return 0;
}