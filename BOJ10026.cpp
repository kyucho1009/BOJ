#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int cnt;
string board[100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue <pair<int, int>> Q;

void bfs(int x, int y)
{
	vis[x][y] = 1;
	Q.push({x, y});
	while(!Q.empty())
	{
		pair <int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y])
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
	cin >> N;
	for (int i = 0; i < N; i++)
		fill(vis[i], vis[i] + N, 0);
	for (int i = 0; i < N; i++)
		cin >> board[i];
	cnt = 0;
	for (int i = 0; i < N; i ++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] != 0)
				continue;
			bfs(i, j);
			cnt++;
		}
	}
	cout << cnt << " ";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}
	for (int i = 0; i < N; i++)
		fill(vis[i], vis[i] + N, 0);
	cnt = 0;
	for (int i = 0; i < N; i ++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] != 0)
				continue;
			bfs(i, j);
			cnt++;
		}
	}
	cout << cnt;
	/*
	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		for (int j = 0; j < N; j++)
			cout << board[i][j];
	}
	*/
	return 0;
}