#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[500][500] = {0,};
bool vis[500][500];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
	int mx = 0; ///그림의 최댓값
	int num = 0; ///그림의 개수
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) ///그림 그리기{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < n; i++) ///그림 찾기
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || vis[i][j])
				continue;
			num++;
			queue <pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({i,j});
			int area = 0;
			while (!Q.empty())
			{
				area++;
				pair<int, int> cur = Q.front();
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
			mx = max(mx, area);
		}
	}
	cout << num << "\n" << mx;
}