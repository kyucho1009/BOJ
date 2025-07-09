#include <bits/stdc++.h>
using namespace std;

int N;
int W;
int H;
int L;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> W >> H >> L;
    ans = min(N, (W / L) * (H / L));
    cout << ans;
    return 0;
}