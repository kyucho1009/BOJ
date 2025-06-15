#include <bits/stdc++.h>
using namespace std;

int n;
int w;
int L;
int ans;
int weight;
vector<int> truck;
queue<int> bridge;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++)
    {
        cin >> weight;
        truck.push_back(weight);
    }
    int sum = 0;
    while (true)
    {
        if (truck.empty())
            break;
        if (bridge.size() == w)
        {
            sum -= bridge.front();
            bridge.pop();
        }
        if (sum + truck.front() > L)
        {
            bridge.push(0);
        }
        else
        {
            bridge.push(truck.front());
            sum += truck.front();
            truck.erase(truck.begin());
        }
        ans++;
    }
    cout << ans + w;
}