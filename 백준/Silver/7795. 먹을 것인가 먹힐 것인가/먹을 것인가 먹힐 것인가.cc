#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int M;
int ans;
int arr1[20001];
int arr2[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        int A;
        int B;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            cin >> arr1[i];
        sort(arr1, arr1 + N);
        for (int i = 0; i < M; i++)
            cin >> arr2[i];
        sort(arr2, arr2 + M);
        int idx;
        idx = 0;
        ans = 0;
        for (int i = 0; i < N; i++)
        {
            while (arr1[i] > arr2[idx])
            {
                if (idx >= M)
                    break;
                idx++;
            }
            ans += idx;
        }
        cout << ans << "\n";
    }
    return 0;
}