#include <bits/stdc++.h>
using namespace std;

int a;
int b;
int c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int idx;
    idx = 1;
    cout << fixed;
    cout.precision(3);
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        cout << "Triangle #" << idx << "\n";
        if (c == -1)
            cout << "c = " << sqrt(a * a + b * b) << "\n";
        else if (a >= c || b >= c)
            cout << "Impossible." << "\n";
        else if (a == 0 || b == 0 || c == 0)
            cout << "Impossible." << "\n";
        else if (a == -1)
            cout << "a = " << sqrt(c * c - b * b) << "\n";
        else if (b == -1)
            cout << "b = " << sqrt(c * c - a * a) << "\n";
        cout << "\n";
        idx++;
    }
    return 0;
}