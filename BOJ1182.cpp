#include <bits/stdc++.h>
using namespace std;

int N;
int S;
int cnt;
int arr[20];
bool isused[20];

void func(int num, int sum)
{
    if (N == num)
    {
        if (sum == S)
            cnt++;
        return;
    }
    func(num + 1, sum);
    func(num + 1, sum + arr[num]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    func(0, 0);
    if (S == 0)
        cnt--;
    cout << cnt;
    return 0;
}