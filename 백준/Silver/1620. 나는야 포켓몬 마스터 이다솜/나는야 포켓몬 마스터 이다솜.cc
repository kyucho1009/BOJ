#include <bits/stdc++.h>
using namespace std;

int N;
int M;
map<int, string> book1;
map<string, int> book2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> book1[i];
        book2[book1[i]] = i;
    }
    for (int i = 0; i < M; i++)
    {
        string ask;
        cin >> ask;
        if ('0' < ask[0] && ask[0] <= '9')
            cout << book1[stoi(ask)] << "\n";
        else
            cout << book2[ask] << "\n";
    }
}