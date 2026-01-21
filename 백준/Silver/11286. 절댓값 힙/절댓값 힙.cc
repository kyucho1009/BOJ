#include <bits/stdc++.h>
using namespace std;

int N;
int num;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        pair<int, int> newnum;
        newnum.first = abs(num);
        newnum.second = num;
        if (num != 0)
        {
            PQ.push(newnum);
        }
        else
        {
            if (PQ.size() == 0)
                cout << 0 << "\n";
            else
            {
                cout << PQ.top().second << "\n";
                PQ.pop();
            }
        }
    }
    return 0;
}