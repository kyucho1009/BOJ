#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int dist[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fill(dist, dist + 100001, -1);
	queue <int> Q;
	dist[N] = 0;
	Q.push(N);
	while (dist[K] == -1)
	{
		int cur = Q.front();
		Q.pop();
		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next < 0 || next > 100000)
				continue;
			if (dist[next] != -1)
				continue;
			dist[next] = dist[cur] + 1;
			Q.push(next);
		}
	}
	cout << dist[K];
	return 0;
}