#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[100001];

int binary_search(int target)
{
    int st;
    int en;
    st = 0;
    en = N - 1;
    while (st <= en)
    {
        int mid;
        mid = (st + en) / 2;
        if (arr[mid] < target)
            st = mid + 1;
        else if (arr[mid] > target)
            en = mid - 1;
        else
            return 1;
    }
    return 0;
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
        cout << binary_search(num) << "\n";
    }
    return 0;
}