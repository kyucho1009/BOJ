#include <bits/stdc++.h>
using namespace std;

long N;
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ans = sqrt(N);
    if (ans * ans < N)
        ans++;
    cout << ans;
    return 0;
}