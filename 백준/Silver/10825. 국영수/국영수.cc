#include <bits/stdc++.h>
using namespace std;

int N;
string name;
int korean;
int english;
int math;

bool compare(const tuple<string, int, int, int> &a, const tuple<string, int, int, int> &b)
{
    if (get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);
    if (get<2>(a) != get<2>(b))
        return get<2>(a) < get<2>(b);
    if (get<3>(a) != get<3>(b))
        return get<3>(a) > get<3>(b);
    return get<0>(a) < get<0>(b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<tuple<string, int, int, int>> V;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> korean >> english >> math;
        V.push_back({name, korean, english, math});
    }
    sort(V.begin(), V.end(), compare);
    for (int i = 0; i < N; i++)
        cout << get<0>(V[i]) << "\n";
    return 0;
}