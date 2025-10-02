#include <bits/stdc++.h>
using namespace std;

int N;
long long sum;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int min;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    min = *min_element(arr, arr + N);
    for (int i = 0; i < N; i++)
        sum += arr[i] - min;
    cout << sum;
    return 0;
}