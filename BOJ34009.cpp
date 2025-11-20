#include <bits/stdc++.h>
using namespace std;

long long N;
long long arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    if (N % 2 == 1)
    {
        cout << "Bob";
        return 0;
    }
    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum == arr[0] * N)
    {
        cout << "Bob";
        return 0;
    }
    cout << "Alice";
    return 0;
}