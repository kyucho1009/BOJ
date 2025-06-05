#include <bits/stdc++.h>
using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (auto c : str)
    {
        if (65 <= c && c <= 90)
            cout << (char)tolower(c);
        else
            cout << (char)toupper(c);
    }
}