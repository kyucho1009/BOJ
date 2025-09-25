#include <bits/stdc++.h>
using namespace std;

int L;
int d;
long long sum;
long long ans;
int arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L;
    ans = -50000000001;
    for (int i = 1; i <= L; i++)
        cin >> arr[i];
    for (int i = 1; i <= L; i++) // 몇칸씩 던질것인가
    {
        sum = 0;
        for (int j = 0; j <= L; j += i) // 점수 합 구하기
            sum += arr[j];
        if (ans < sum)
        {
            ans = sum;
            d = i;
        }
    }
    if (ans < 0)
        cout << 0 << " " << 0;
    else
        cout << d << " " << ans;
    return 0;
}