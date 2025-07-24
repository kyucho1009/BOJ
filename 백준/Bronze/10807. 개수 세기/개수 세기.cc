#include <bits/stdc++.h>
using namespace std;

int N;
int v;
int cnt;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cin >> v;
    for (auto k : arr)
        if (k == v)
            cnt++;
    cout << cnt;
    return 0;
}