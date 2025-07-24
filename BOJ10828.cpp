#include <bits/stdc++.h>
using namespace std;

int testcase;
string s;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> testcase;
    while (testcase--)
    {
        cin >> s;

        if (s == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }

        else if (s == "pop")
        {
            if (st.empty())
                cout << "-1\n";
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }

        else if (s == "size")
            cout << st.size() << "\n";

        else if (s == "empty")
            cout << st.empty() << "\n";

        else if (s == "top")
        {
            if (st.empty())
                cout << "-1\n";
            else
                cout << st.top() << "\n";
        }
    }
    return 0;
}