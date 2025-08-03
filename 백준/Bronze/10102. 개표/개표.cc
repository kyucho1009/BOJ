#include <bits/stdc++.h>
using namespace std;

int N;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> str;
    int a;
    int b;
    a = 0;
    b = 0;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == 'A')
            a++;
        else
            b++;
    }
    if (a > b)
        cout << "A";
    else if (a < b)
        cout << "B";
    else
        cout << "Tie";
    return 0;
}