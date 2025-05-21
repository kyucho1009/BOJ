#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[10];
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
    for (int i = 1; i <= N; i++)
    {
        // 사용된 숫자인가, 이전보다 큰 숫자인가
        if (num == 0)
        {
            if (!isused[i])
            {
                arr[num] = i;
                isused[i] = 1;
                func(num + 1);
                isused[i] = 0;
            }
        }
        else
        {
            if (!isused[i] && arr[num - 1] < i)
            {
                arr[num] = i;
                isused[i] = 1;
                func(num + 1);
                isused[i] = 0;
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