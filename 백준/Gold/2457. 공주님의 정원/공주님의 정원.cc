#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
vector<pair<int, int>> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        int b;
        int c;
        int d;
        int st;
        int ed;
        cin >> a >> b >> c >> d;
        st = a * 100 + b;
        ed = c * 100 + d;
        V.push_back({st, ed});
    }
    sort(V.begin(), V.end());
    if (V[0].first > 301)
    {
        cout << 0;
        return 0;
    }
    int idx = 0;
    int tmp = 301;
    while (tmp < 1201)
    {
        int mx = tmp;

        while (idx < N && V[idx].first <= tmp)
        {
            mx = max(mx, V[idx].second);
            idx++;
        }
        if (mx <= tmp)
        {
            cout << 0;
            return 0;
        }
        tmp = mx;
        cnt++;
    }
    cout << cnt;
    return 0;
}