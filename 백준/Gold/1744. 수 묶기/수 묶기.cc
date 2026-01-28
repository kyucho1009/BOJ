#include <bits/stdc++.h>
using namespace std;

int N;
long long ans;
vector<int> pos;
vector<int> notpos;

bool compare(const int a, const int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num > 0)
            pos.push_back(num);
        else
            notpos.push_back(num);
    }
    sort(pos.begin(), pos.end(), compare);
    sort(notpos.begin(), notpos.end());
    int idx = 0;
    bool iseven = false;
    if (notpos.size() % 2 == 0)
        iseven = true;
    while (true)
    {
        if (idx == pos.size())
            break;
        if ((pos[idx] > 1) && (pos[idx + 1] > 1))
        {
            ans += pos[idx] * pos[idx + 1];
            idx += 2;
        }
        else if ((idx == pos.size() - 1) && !iseven)
        {
            ans += pos[idx];
            idx++;
        }
        else
        {
            ans += pos[idx];
            idx++;
        }
    }
    idx = 0;
    iseven = false;
    if (notpos.size() % 2 == 0)
        iseven = true;
    while (true)
    {
        if (idx == notpos.size())
            break;
        if ((idx == notpos.size() - 1) && !iseven)
        {
            ans += notpos[idx];
            idx++;
        }
        else
        {
            ans += notpos[idx] * notpos[idx + 1];
            idx += 2;
        }
    }
    cout << ans;
}