#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int B;
int board[501][501];
vector<pair<int, int>> V;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    int maxHeight;
    maxHeight = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            maxHeight += board[i][j];
    maxHeight += B;
    maxHeight /= (N * M);
    int add;
    int del;
    for (int i = 0; i <= maxHeight; i++)
    {
        add = 0;
        del = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (i < board[j][k])
                    del += (board[j][k] - i);
                else
                    add += (i - board[j][k]);
            }
        }
        V.push_back({del * 2 + add, i});
    }
    sort(V.begin(), V.end(), compare);
    cout << V.front().first << " " << V.front().second;

    return 0;
}