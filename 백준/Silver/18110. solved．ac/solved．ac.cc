#include <bits/stdc++.h>
using namespace std;

int n;
int cut;
int level;
double ans;
vector<int> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> level;
        V.push_back(level);
    }
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    cut = round(n * 0.15);
    sort(V.begin(), V.end());
    for (int i = cut; i < n - cut; i++)
        ans += V[i];
    cout << round(ans / (n - cut * 2));
    return 0;
}