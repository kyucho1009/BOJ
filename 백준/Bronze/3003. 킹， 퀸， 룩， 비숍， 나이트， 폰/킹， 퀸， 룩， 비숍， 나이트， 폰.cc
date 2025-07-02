#include <bits/stdc++.h>
using namespace std;

int king;
int queen;
int rook;
int bishop;
int knight;
int pone;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> king >> queen >> rook >> bishop >> knight >> pone;
    cout << 1 - king << " " << 1 - queen << " " << 2 - rook << " " << 2 - bishop << " " << 2 - knight << " " << 8 - pone;
    return 0;
}