#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int cnt;
bool isclose[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < 101; i++)
            isclose[i] = 0;
        for (int i = 2; i <= N; i++)
            for (int j = i; j <= N; j += i)
                isclose[j] = !isclose[j];
        cnt = 0;
        for (int i = 1; i <= N; i++)
            if (isclose[i] == 0)
                cnt++;
        cout << cnt << "\n";
    }
    return 0;
}