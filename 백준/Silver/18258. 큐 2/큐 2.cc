#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num;
    int order_num;
    string order;
    queue <int> q;

    cin >> order_num;
    for (int i = 0; i < order_num; i++)
    {
        cin >> order;
        if (order == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (order == "pop")
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (order == "size")
            cout << q.size() << "\n";
        else if (order == "empty")
        {
            if (!q.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
        else if (order == "front")
        {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        }
        else if (order == "back")
        {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1\n";
        }
    }
}