#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
vector<int> V{3};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> V[0] >> V[1] >> V[2];
        if (V[0] == -1 && V[1] == -1 && V[2] == -1)
            continue;
        for (int i = 0; i < 3; i++)
            if (V[i] == -1)
                V[i] = 121;
        if (V[0] <= V[1] && V[1] <= V[2])
            cnt++;
    }
    cout << cnt;
    return 0;
}