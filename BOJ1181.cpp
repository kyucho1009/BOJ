#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> arr;

bool compare(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (auto k : arr)
        cout << k << "\n";
    return 0;
}