#include <bits/stdc++.h>
using namespace std;

int N;
int DP[1500051];
pair<int, int> arr[1500051];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i].first >> arr[i].second;
    int mx;
    mx = 0;
    for (int i = 1; i <= N; i++)
    {
        mx = max(mx, DP[i]);
        DP[i + arr[i].first] = max(arr[i].second + mx, DP[i + arr[i].first]);
    }
    cout << *max_element(DP + 1, DP + N + 2);
    return 0;
}