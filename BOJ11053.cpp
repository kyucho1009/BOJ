#include <bits/stdc++.h>
using namespace std;

int N;
int num[1001];
int DP[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (num[j] < num[i])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }
    cout << *max_element(DP + 1, DP + N + 1);
    return 0;
}