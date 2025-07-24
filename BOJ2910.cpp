#include <bits/stdc++.h>
using namespace std;

int N;
int C;
vector<pair<int, int>> arr;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        bool check;
        check = false;
        for (auto &k : arr)
        {
            if (k.second == num)
            {
                k.first++;
                check = true;
                break;
            }
        }
        if (!check)
            arr.push_back({1, num});
    }
    stable_sort(arr.begin(), arr.end(), compare);
    for (auto k : arr)
    {
        while (k.first--)
            cout << k.second << " ";
    }
    return 0;
}