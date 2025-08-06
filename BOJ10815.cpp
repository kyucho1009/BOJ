#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        cout << upper_bound(arr, arr + N, num) - lower_bound(arr, arr + N, num) << " ";
    }
    return 0;
}