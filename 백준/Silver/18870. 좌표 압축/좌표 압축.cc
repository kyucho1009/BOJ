#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001];
vector<int> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        V.push_back(arr[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for (int i = 0; i < N; i++)
        cout << lower_bound(V.begin(), V.end(), arr[i]) - V.begin() << " ";
    return 0;
}