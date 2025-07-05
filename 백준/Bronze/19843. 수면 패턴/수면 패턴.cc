#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int sum;
pair<int, int> wake;
pair<int, int> sleep;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> N;
    while (N--)
    {
        string day;
        cin >> day >> sleep.second;
        if (day == "Mon")
            sleep.first = 1;
        else if (day == "Tue")
            sleep.first = 2;
        else if (day == "Wed")
            sleep.first = 3;
        else if (day == "Thu")
            sleep.first = 4;
        else
            sleep.first = 5;
        cin >> day >> wake.second;
        if (day == "Mon")
            wake.first = 1;
        else if (day == "Tue")
            wake.first = 2;
        else if (day == "Wed")
            wake.first = 3;
        else if (day == "Thu")
            wake.first = 4;
        else
            wake.first = 5;
        if (sleep.first != wake.first)
            sum += (wake.second - sleep.second + 24 * (wake.first - sleep.first));
        else
            sum += (wake.second - sleep.second);
    }
    if (T <= sum)
        cout << 0;
    else if (T - sum <= 48)
        cout << T - sum;
    else
        cout << -1;
    return 0;
}