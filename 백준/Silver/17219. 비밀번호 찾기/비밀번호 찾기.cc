#include <bits/stdc++.h>
using namespace std;

int N;
int M;
map<string, string> text;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    string address;
    string password;
    for (int i = 0; i < N; i++)
    {
        cin >> address >> password;
        text[address] = password;
    }
    string ans;
    for (int i = 0; i < M; i++)
    {
        cin >> ans;
        cout << text[ans] << "\n";
    }
    return 0;
}