#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define Z third

int M;
int N;
int H;
int ans;
int board[100][100][100];
int dist[100][100][100];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
queue <tuple<int, int, int>> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					Q.push({i, j, k});
				if (board[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}
	while (!Q.empty())
	{
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= H || ny < 0 || ny >= N || nz < 0 || nz >= M)
				continue;
			if (dist[nx][ny][nz] >= 0 || board[nx][ny][nz] == -1)
				continue;
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({nx, ny, nz});
		}
	}
	ans = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
	/*
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "\n";
			for (int k = 0; k < M; k++)
				cout << board[i][j][k] << " ";
		}
	}
	*/
	return 0;
}