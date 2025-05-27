#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[10];
int digit[10];
bool isused[10];

void func(int num)
{
    if (num == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (!isused[i] && tmp != digit[i])
        {
            arr[num] = digit[i];
            isused[i] = 1;
            tmp = arr[num];
            func(num + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> digit[i];
    sort(digit, digit + N);
    func(0);
    return 0;
}