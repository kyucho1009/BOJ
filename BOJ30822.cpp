#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
int arr[5];
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> str;
    for (auto k : str)
    {
        if (k == 'u')
            arr[0]++;
        else if (k == 'o')
            arr[1]++;
        else if (k == 's')
            arr[2]++;
        else if (k == 'p')
            arr[3]++;
        else if (k == 'c')
            arr[4]++;
    }
    ans = 1000;
    for (auto k : arr)
        ans = min(ans, k);
    cout << ans;
    return 0;
}