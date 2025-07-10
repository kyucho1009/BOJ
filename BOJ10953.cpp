#include <bits/stdc++.h>
using namespace std;

int T;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> str;
        string tmp;
        istringstream ss(str);
        vector<string> V;
        while (getline(ss, tmp, ','))
            V.push_back(tmp);
        cout << stoi(V.front()) + stoi(V.back()) << "\n";
    }
    return 0;
}