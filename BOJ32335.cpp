#include <bits/stdc++.h>
using namespace std;

int N;
int M;
string num;
int arr[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> num;
    for (int i = 0; i < N; i++)
        arr[i] = num[i] - 48;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
            continue;
        if (arr[i] + M > 9)
        {
            M = (arr[i] + M) - 10;
            arr[i] = 0;
        }
    }
    if (M > 0)
    {
        arr[N - 1] += M;
        arr[N - 1] %= 10;
    }
    for (int i = 0; i < N; i++)
        cout << arr[i];
    return 0;
}