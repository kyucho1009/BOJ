#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int flag;
    string str;
    while (1)
    {
        flag = 1;
        stack <char> s;
        getline(cin, str);
        if (str == ".")
            break;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else if (!s.empty() && str[i] == ')' && s.top() == '(')
                s.pop();
            else if (!s.empty() && str[i] == ']' && s.top() == '[')
                s.pop();
            else if (65 <= str[i] && str[i] <= 90)
                continue;
            else if (97 <= str[i] && str[i] <= 122)
                continue;
            else if (str[i] == '.' || str[i] == ' ')
                continue;
            else
            {
                flag =-1;
                break;
            }
        }
        if (flag == 1 && s.empty())
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
}