#include <bits/stdc++.h>
using namespace std;

int N;
int num;
priority_queue<int> PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num == 0)
        {
            if (PQ.empty())
                cout << 0 << "\n";
            else
            {
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        }
        else
            PQ.push(num);
    }
    return 0;
}