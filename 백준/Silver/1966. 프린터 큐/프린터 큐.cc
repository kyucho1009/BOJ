#include <bits/stdc++.h>
using namespace std;

int cnt;
int num;
int val;
int idx;
int test_case;

int main()
{

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        cnt = 0;
        cin >> num >> idx;
        for (int j = 0; j < num; j++)
        {
            cin >> val;
            q.push({val, j});
            pq.push(val);
        }
        while (!q.empty())
        {
            if (pq.top() == q.front().first)
            {
                pq.pop();
                cnt++;
                if (q.front().second == idx)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else
                q.push(q.front());
            q.pop();
        }
    }
    return 0;
}