#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int day[31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int start;
    int end;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        for (int j = start; j < end; j++)
            day[j] += 1;
    }
    cin >> K;
    int mx;
    mx = 0;
    for (auto i : day)
        mx = max(mx, i);
    if (mx <= K)
        cout << 1;
    else
        cout << 0;
}