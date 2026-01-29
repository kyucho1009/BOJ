#include <bits/stdc++.h>
using namespace std;

int N;
long long ans;
pair<int, int> pos[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> pos[i].first >> pos[i].second;
    sort(pos, pos + N);
    long long st = pos[0].first;
    long long ed = pos[0].second;
    for (int i = 1; i < N; i++)
    {
        if ((pos[i].first <= ed) && (pos[i].second > ed))
            ed = pos[i].second;
        else if (pos[i].first > ed)
        {
            ans += (ed - st);
            st = pos[i].first;
            ed = pos[i].second;
        }
    }
    ans += (ed - st);
    cout << ans;
    return 0;
}