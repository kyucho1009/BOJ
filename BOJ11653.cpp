#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int num;
    num = N;
    for (int i = 2; i <= N; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            cout << i << "\n";
        }
    }
    return 0;
}