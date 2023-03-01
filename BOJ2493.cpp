#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num = 0;
    int height = 0;
    int tower = 0;
    int cnt = 0;
    stack <int> s;
    stack <int> temp;
    stack <int> result;
    
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> height;
        s.push(height);
    }

    for (int i = 0; i < num; i++)
    {
        cnt = 0;
        tower = s.top();
        s.pop();
        for (int j = 0; j < s.size(); j++)
        {
            temp.push(s.top());
            if (tower < s.top())
                cnt++;
            s.pop();
        }
        for (int j = 0; j < temp.size(); j++)
        {
            s.push(temp.top());
            temp.pop();
        }
        result.push(cnt);
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}