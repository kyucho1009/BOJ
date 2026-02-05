#include <bits/stdc++.h>
using namespace std;

int L;
int P;
int V;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cnt = 1;
    while (true)
    {
        cin >> L >> P >> V;
        if ((L + P + V) == 0)
            break;
        cout << "Case " << cnt << ": " << L * (V / P) + min(L, (V % P)) << "\n";
        cnt++;
    }
    return 0;
}