#include <bits/stdc++.h>
using namespace std;

int N;
int sum;
int arr[100001];
pair<int, int> cur;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    sum = 2000000000;
    for (int i = 0; i < N - 1; i++)
    {
        int idx;
        int target;
        target = -arr[i];
        idx = lower_bound(arr + i + 1, arr + N, target) - arr;
        if (idx < N) // lower_bound의 반환값이 N인 경우 제외
        {
            if (sum > abs(arr[i] + arr[idx]))
            {
                sum = abs(arr[i] + arr[idx]);
                cur = {arr[i], arr[idx]};
            }
        }
        if (idx - 1 > i) // idx - 1값이 i 이하인 경우 제외
        {
            if (sum > abs(arr[i] + arr[idx - 1]))
            {
                sum = abs(arr[i] + arr[idx - 1]);
                cur = {arr[i], arr[idx - 1]};
            }
        }
    }
    cout << cur.first << " " << cur.second;
    return 0;
}