#include <bits/stdc++.h>
using namespace std;

long long func(long long a, long long b, long long m)
{
    if (b == 1)
        return a % m;
    long long val = func(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0)
        return val;
    return val * a % m;
}

int main(void)
{
    int A;
    int B;
    int C;

    cin >> A >> B >> C; // 10 11 12
    cout << func(A, B, C);
    return 0;
}