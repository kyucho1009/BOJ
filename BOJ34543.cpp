#include <bits/stdc++.h>
using namespace std;

int N;
int W;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> W;
    ans += 10 * N;
    if (N > 2)
        ans += 20;
    if (N == 5)
        ans += 50;
    if (W > 1000)
        ans -= 15;
    if (ans < 0)
        cout << 0;
    else
        cout << ans;
    return 0;
}