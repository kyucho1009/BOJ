#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[1000];
int dist1[1000][1000];
int dist2[1000][1000];
int row;
int col;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue <pair<int, int>> Q1;
	queue <pair<int, int>> Q2;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		cin >> board[i];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'F')
			{
				Q1.push({i, j});
				dist1[i][j] = 1;
			}
			if (board[i][j] == 'J')
			{
				Q2.push({i, j});
				dist2[i][j] = 1;
			}
		}
	}
	while (!Q1.empty())
	{
		pair<int, int> cur = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
				continue;
			if (dist1[nx][ny] != 0 || board[nx][ny] == '#')
				continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({nx, ny});
		}
	}
	while (!Q2.empty())
	{
		pair <int, int> cur = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
			{
				cout << dist2[cur.X][cur.Y];
				return 0;
			}
			if (dist2[nx][ny] != 0 || board[nx][ny] == '#')
				continue;
			if (dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 && dist1[nx][ny] > 0)
				continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
    /*
	만약 지훈이가 가는 좌표가 불이 도달할 수 없는 장소라면
	해당 좌표의 값은 항상 0
	따라서 dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 조건 성립으로 continue를 실행
	그러므로 위의 조건을 다른 조건들과 분리
	*/
	/*
	cout << "---------" << "\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << dist1[i][j];
		cout << "\n";
	}
	
	cout << "---------" << "\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << dist2[i][j];
		cout << "\n";
	}
	*/
	return 0;
}