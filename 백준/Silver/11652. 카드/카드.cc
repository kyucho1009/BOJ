#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
int mxcnt;
long long mxval;
long long arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    mxval = -4611686018427387905;
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || arr[i] == arr[i - 1])
            cnt++;
        else
        {
            if (mxcnt < cnt)
            {
                mxcnt = cnt;
                mxval = arr[i - 1];
            }
            cnt = 1;
        }
    }
    if (mxcnt < cnt)
        mxval = arr[N - 1];
    cout << mxval;
    return 0;
}