#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[100];
int vis[100][100] = {0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
	int mn;
	queue <pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({0,0});
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> board[i];

	while(!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) ///board 내의 값이 맞는지 확인
				continue;
			if(board[nx][ny] == '0' || vis[nx][ny] != 0) ///이미 방문했거나 파란칸이 아닌 경우 스킵(빨간 칸인 경우)
				continue;
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	cout << vis[n - 1][m - 1];
}