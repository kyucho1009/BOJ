#include <bits/stdc++.h>
using namespace std;

string S;
string arr[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    for (int i = 0; i < S.length(); i++)
        arr[i] = S.substr(i, S.length() - i);
    sort(arr, arr + S.length());
    for (int i = 0; i < S.length(); i++)
        cout << arr[i] << "\n";
    return 0;
}