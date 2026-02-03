#include <bits/stdc++.h>
using namespace std;

int N;
int num;
int cnt;
bool isprime;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cnt = N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num == 1)
        {
            cnt--;
            continue;
        }
        for (int j = 2; j * j <= num; j++)
            if (num % j == 0)
            {
                cnt--;
                break;
            }
    }
    cout << cnt;
    return 0;
}