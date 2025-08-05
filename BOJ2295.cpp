#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    vector<int> V;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            V.push_back(arr[i] + arr[j]);
    sort(V.begin(), V.end());
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (binary_search(V.begin(), V.end(), arr[i] - arr[j]))
            {
                cout << arr[i];
                return 0;
            }
        }
    }
}