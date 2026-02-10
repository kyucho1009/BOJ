#include <bits/stdc++.h>
using namespace std;

int N;
bool isprime[246913];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < 246913; i++)
        isprime[i] = 1;
    for (int i = 2; i < 246913; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = 2 * i; j < 246913; j += i)
            isprime[j] = 0;
    }
    int cnt;
    while (true)
    {
        cnt = 0;
        cin >> N;
        if (N == 0)
            return 0;
        for (int i = N + 1; i <= N * 2; i++)
            if (isprime[i])
                cnt++;
        cout << cnt << "\n";
    }
}