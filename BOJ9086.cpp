#include <bits/stdc++.h>
using namespace std;

int test_case;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_case;
    while (test_case--)
    {
        cin >> str;
        cout << str.front() << str.back() << "\n";
    }
    return 0;
}