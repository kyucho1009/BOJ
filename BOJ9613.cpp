#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int num[101];
long long sum;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> num[i];
        sum = 0;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                sum += gcd(num[i], num[j]);
        cout << sum << "\n";
    }
    return 0;
}