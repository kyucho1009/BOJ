#include <bits/stdc++.h>
using namespace std;

int T;
int num;
string s;
queue<int> q;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;

        if (s == "push")
        {
            cin >> num;
            q.push(num);
        }

        else if (s == "pop")
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        else if (s == "size")
            cout << q.size() << "\n";

        else if (s == "empty")
            cout << q.empty() << "\n";

        else if (s == "front")
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        }

        else if (s == "back")
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}