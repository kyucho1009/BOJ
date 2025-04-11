#include <bits/stdc++.h>
using namespace std;

int N;
int r;
int c;

int func(int n, int x, int y)
{
    if (n == 0)
        return 0;
    int half;
    half = 1 << (n - 1);
    if (x < half && y < half)
        return func(n - 1, x, y);
    else if (x < half && y >= half)
        return half * half + func(n - 1, x, y - half);
    else if (x >= half && y < half)
        return 2 * half * half + func(n - 1, x - half, y);
    else
        return 3 * half * half + func(n - 1, x - half, y - half);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> r >> c;
    cout << func(N, r, c);
    return 0;
}