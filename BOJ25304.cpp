#include <bits/stdc++.h>
using namespace std;

int X;
int N;
int a;
int b;
int sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> X >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        sum += a * b;
    }
    if (X == sum)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}