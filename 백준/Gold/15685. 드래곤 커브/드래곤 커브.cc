#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int x;
int y;
int d;
int g;
bool board[102][102];
vector<pair<int, int>> V;

void rotate()
{
    vector<pair<int, int>> NV;
    pair<int, int> point = V.back();
    for (auto i = V.rbegin() + 1; i != V.rend(); ++i)
    {
        int nx = point.X - (i->Y - point.Y);
        int ny = point.Y + (i->X - point.X);
        NV.push_back({nx, ny});
    }
    V.insert(V.end(), NV.begin(), NV.end());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> x >> y >> d >> g;
        V.clear();
        V.push_back({x, y});
        if (d == 0)
            V.push_back({x + 1, y});
        else if (d == 1)
            V.push_back({x, y - 1});
        else if (d == 2)
            V.push_back({x - 1, y});
        else if (d == 3)
            V.push_back({x, y + 1});
        while (g--)
            rotate();
        for (auto i : V)
            board[i.X][i.Y] = 1;
    }
    int cnt;
    cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                cnt++;
        }
    }
    cout << cnt;
}