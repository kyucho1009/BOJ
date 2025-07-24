#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string str;
    long long num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        str = to_string(num);
        reverse(str.begin(), str.end());
        arr[i] = stoll(str);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}