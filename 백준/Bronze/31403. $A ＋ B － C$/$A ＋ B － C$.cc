#include <bits/stdc++.h>
using namespace std;

int A;
int B;
int C;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;
    cout << A + B - C << "\n";
    string a = to_string(A);
    string b = to_string(B);
    a.append(b);
    A = stoi(a);
    cout << A - C;
    return 0;
}