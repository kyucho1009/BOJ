#include <bits/stdc++.h>
using namespace std;

int N;
string name;
string school;
string ICPC;
int shake;
int APC;

bool compare(pair<int, string> p1, pair<int, string> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<pair<int, string>> V;
    while (N--)
    {
        cin >> name >> school >> ICPC >> shake >> APC;
        if (school == "hewhak")
            continue;
        if (ICPC == "winner")
            continue;
        if (0 < shake && shake < 4)
            continue;
        V.push_back({APC, name});
    }
    sort(V.begin(), V.end());
    while (V.size() > 10)
        V.pop_back();
    sort(V.begin(), V.end(), compare);
    cout << V.size() << "\n";
    for (auto k : V)
        cout << k.second << "\n";
    return 0;
}