#include <bits/stdc++.h>
using namespace std;

int N;
int DP[1001];
pair<int, int> arr[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i].first >> arr[i].second;
    int day;
    day = 0;
    for (int i = 1; i <= N + 1; i++) // 기준점
    {
        for (int j = 1; j < i; j++) // 기준점 아래 탐색
        {
            if (j + arr[j].first <= i)
                DP[i] = max(DP[i], DP[j] + arr[j].second);
        }
    }
    cout << *max_element(DP + 1, DP + N + 2);
    return 0;
}