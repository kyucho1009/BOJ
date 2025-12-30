#include <bits/stdc++.h>
using namespace std;

int N;
int sum[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> sum[i];
        if (sum[i - 1] + sum[i] > sum[i])
            sum[i] += sum[i - 1];
    }
    cout << *max_element(sum + 1, sum + N + 1);
    return 0;
}