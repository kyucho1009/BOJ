#include <bits/stdc++.h>
using namespace std;

int N;
int num;
int arr[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr[num]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        while (arr[i]--)
            cout << i << "\n";
    }
    return 0;
}