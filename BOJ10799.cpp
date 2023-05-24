#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int cnt;
    char save;
    string str;
    stack<int> s;

    cnt = 0;
    cin >> str;
    for (auto bracket : str)
    {
        if (bracket == '(')
            s.push(bracket);
        else if (bracket == ')')
        {
            if (save != bracket)
            {
                s.pop();
                cnt += s.size();
            }
            else
            {
                s.pop();
                cnt += 1;
            }
        }
        save = bracket;
    }
    cout << cnt;
    return 0;
}