#include <bits/stdc++.h>
using namespace std;

int T;
int r1;
int r2;
pair<int, int> pos1;
pair<int, int> pos2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> pos1.first >> pos1.second >> r1 >> pos2.first >> pos2.second >> r2;
        int dis;
        dis = (pos1.first - pos2.first) * (pos1.first - pos2.first) + (pos1.second - pos2.second) * (pos1.second - pos2.second);
        if (dis == 0)
        {
            if (r1 != r2)
                cout << 0;
            else
                cout << -1;
        }
        else if (dis < r1 * r1 || dis < r2 * r2)
        {
            if (dis > (r2 - r1) * (r2 - r1) || dis > (r1 - r2) * (r1 - r2))
                cout << 2;
            else if (dis == (r2 - r1) * (r2 - r1) || dis == (r1 - r2) * (r1 - r2))
                cout << 1;
            else
                cout << 0;
        }
        else
        {
            if (dis < (r1 + r2) * (r1 + r2))
                cout << 2;
            else if (dis == (r1 + r2) * (r1 + r2))
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
    return 0;
}