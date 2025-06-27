#include <bits/stdc++.h>
using namespace std;

int ans;
string str[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 3; i++)
        cin >> str[i];
    for (int i = 0; i < 3; i++)
    {
        if (str[i] != "Fizz" && str[i] != "Buzz" && str[i] != "FizzBuzz")
        {
            ans = stoi(str[i]) + (3 - i);
            break;
        }
        else
            continue;
    }
    if (ans % 15 == 0)
        cout << "FizzBuzz";
    else if (ans % 5 == 0)
        cout << "Buzz";
    else if (ans % 3 == 0)
        cout << "Fizz";
    else
        cout << ans;
    return 0;
}