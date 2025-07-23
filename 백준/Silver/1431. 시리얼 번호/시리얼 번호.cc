#include <bits/stdc++.h>
using namespace std;

int N;
string arr[51];

bool compare(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    int sum1;
    int sum2;
    sum1 = 0;
    sum2 = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] >= '0' && a[i] <= '9')
            sum1 += a[i] - 48;
    for (int i = 0; i < b.length(); i++)
        if (b[i] >= '0' && b[i] <= '9')
            sum2 += b[i] - 48;
    if (sum1 != sum2)
        return sum1 < sum2;
    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N, compare);
    for (int i = 0; i < N; i++)
        cout << arr[i] << "\n";
    return 0;
}