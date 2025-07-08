#include <bits/stdc++.h>
using namespace std;

int N;
int sum;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> str;
    int start;
    start = 0;
    int end;
    int size;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == '.' || str[i] == '|' || str[i] == ':' || str[i] == '#')
        {
            end = i;
            size = end - start;
            sum += stoi(str.substr(start, size));
            start = end + 1;
        }
        if (i == N - 1)
        {
            end = N;
            size = end - start;
            sum += stoi(str.substr(start, size));
        }
    }
    cout << sum;
}