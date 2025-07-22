#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
        cout << arr[i].second << " " << arr[i].first << "\n";
    return 0;
}