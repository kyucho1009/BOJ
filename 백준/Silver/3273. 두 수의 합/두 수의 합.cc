#include <bits/stdc++.h>
using namespace std;

int N;
int X;
int cnt;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    cin >> X;
    int st;
    int en;
    st = 0;
    en = N - 1;
    while (st < en)
    {
        int target;
        target = arr[st] + arr[en];
        if (target < X)
            st++;
        else if (target > X)
            en--;
        else
        {
            cnt++;
            st++;
        }
    }
    cout << cnt;
    return 0;
}