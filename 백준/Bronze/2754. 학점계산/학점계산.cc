#include <bits/stdc++.h>
using namespace std;

string score;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> score;
    if (score == "A+")
        cout << "4.3";
    else if (score == "A0")
        cout << "4.0";
    else if (score == "A-")
        cout << "3.7";
    else if (score == "B+")
        cout << "3.3";
    else if (score == "B0")
        cout << "3.0";
    else if (score == "B-")
        cout << "2.7";
    else if (score == "C+")
        cout << "2.3";
    else if (score == "C0")
        cout << "2.0";
    else if (score == "C-")
        cout << "1.7";
    else if (score == "D+")
        cout << "1.3";
    else if (score == "D0")
        cout << "1.0";
    else if (score == "D-")
        cout << "0.7";
    else
        cout << "0.0";
}