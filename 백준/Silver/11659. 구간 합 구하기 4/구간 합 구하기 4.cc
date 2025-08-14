#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[100001];
long long sum[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 1; i < N + 1; i++)
        sum[i] = sum[i - 1] + arr[i - 1];
    for (int i = 0; i < M; i++)
    {
        int st;
        int en;
        cin >> st >> en;
        cout << sum[en] - sum[st - 1] << "\n";
    }
    return 0;
}