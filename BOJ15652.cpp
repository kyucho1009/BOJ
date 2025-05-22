#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[10];

void func(int num)
{
    if (num == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (num == 0)
        {
            arr[num] = i;
            func(num + 1);
        }
        else
        {
            if (arr[num - 1] <= i)
            {
                arr[num] = i;
                func(num + 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
    return 0;
}