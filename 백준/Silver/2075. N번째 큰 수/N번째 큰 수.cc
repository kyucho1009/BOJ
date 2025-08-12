#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2250001];

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int num = N * N;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    sort(arr, arr + num, compare);
    cout << arr[N - 1];
    return 0;
}