#include <bits/stdc++.h>
using namespace std;

int num;
queue<int> q;

int main()
{
    cin >> num;
    for (int i = 1; i <= num; i++)
        q.push(i);
    while (q.size() != 1)
    {
        q.pop();
        if (q.size() == 1)
            break;
        q.push(q.front());
        q.pop();
    }
    cout << q.front();

    return 0;
}