#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--)
    {
        int a;
        int b;
        cin >> a >> b;
        arr[a]++;
        arr[b]++;
    }
    for (int i = 1; i <= N; i++)
        cout << arr[i] << "\n";
    return 0;
}