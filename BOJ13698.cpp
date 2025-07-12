#include <bits/stdc++.h>
using namespace std;

int cup[4];
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cup[0] = -1;
    cup[3] = 1;
    cin >> str;
    for (auto c : str)
    {
        if (c == 'A')
            swap(cup[0], cup[1]);
        else if (c == 'B')
            swap(cup[0], cup[2]);
        else if (c == 'C')
            swap(cup[0], cup[3]);
        else if (c == 'D')
            swap(cup[1], cup[2]);
        else if (c == 'E')
            swap(cup[1], cup[3]);
        else
            swap(cup[2], cup[3]);
    }
    int small;
    int big;
    for (int i = 0; i < 4; i++)
    {
        if (cup[i] == -1)
            small = i;
        else if (cup[i] == 1)
            big = i;
    }
    cout << small + 1 << "\n"
         << big + 1;
    return 0;
}