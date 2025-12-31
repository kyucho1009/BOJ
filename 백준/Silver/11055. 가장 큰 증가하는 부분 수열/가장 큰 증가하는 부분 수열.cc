#include <bits/stdc++.h>
using namespace std;

int N;
int num[1001];
int sum[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    num[0] = 2147483647;
    for (int i = 1; i <= N; i++)
    {
        sum[i] = num[i];
        for (int j = 1; j < i; j++)
        {
            if (num[j] < num[i])
                sum[i] = max(sum[i], sum[j] + num[i]);
        }
    }
    cout << *max_element(sum + 1, sum + N + 1);
    return 0;
}