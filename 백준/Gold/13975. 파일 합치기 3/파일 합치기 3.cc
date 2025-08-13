#include <bits/stdc++.h>
using namespace std;

int T;
int K;
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        priority_queue<long long, vector<long long>, greater<long long>> PQ;
        cin >> K;
        int num;
        for (int i = 0; i < K; i++)
        {
            cin >> num;
            PQ.push(num);
        }
        long long sum;
        ans = 0;
        while (PQ.size() != 1)
        {
            sum = 0;
            sum += PQ.top();
            PQ.pop();
            sum += PQ.top();
            PQ.pop();
            PQ.push(sum);
            ans += sum;
        }
        cout << ans << "\n";
    }
}