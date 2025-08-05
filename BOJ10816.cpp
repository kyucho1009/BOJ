#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[500001];

int lower_idx(int target)
{
    int st;
    int en;
    st = 0;
    en = N;
    while (st < en)
    {
        int mid;
        mid = (st + en) / 2;
        if (arr[mid] >= target)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

int upper_idx(int target)
{
    int st;
    int en;
    st = 0;
    en = N;
    while (st < en)
    {
        int mid;
        mid = (st + en) / 2;
        if (arr[mid] > target)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

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
        cout << upper_idx(num) - lower_idx(num) << " ";
    }
    return 0;
}