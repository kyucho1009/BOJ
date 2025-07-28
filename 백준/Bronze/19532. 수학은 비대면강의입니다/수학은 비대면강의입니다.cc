#include <bits/stdc++.h>
using namespace std;

int a;
int b;
int c;
int d;
int e;
int f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    cout << (c * e - b * f) / (a * e - b * d) << " " << (a * f - d * c) / (a * e - b * d);
    return 0;
}