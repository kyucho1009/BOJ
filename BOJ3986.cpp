#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int         cnt;
    int         test_case;
    string      word;

    cnt = 0;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> word;
        stack <int> s;
        if (word.length() % 2 == 1)
            continue;
        else
        {
            for (auto alphabet:word)
            {
                if (s.empty())
                    s.push(alphabet);
                else if (s.top() != alphabet)
                    s.push(alphabet);
                else
                    s.pop();
            }
            if (s.empty())
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}