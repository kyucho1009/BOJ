#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int cnt;
int ans;
int num[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        num[i] = i;
    for (int i = 2; i <= N; i++)
    {
        if (num[i] == 0)
            continue;
        for (int j = i; j <= N; j += i)
        {
            if (num[j] == 0)
                continue;
            else
            {
                num[j] = 0;
                cnt++;
            }
            if (cnt == K)
                ans = j;
        }
    }
    cout << ans;
    return 0;
}