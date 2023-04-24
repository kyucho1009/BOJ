#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size;
    int number;
    long long cnt;
    pair <int, int> p;
    stack <pair <int, int>> s;

    cnt = 0;
    cin >> size;

    for (int idx = 0; idx < size; idx++)
    {
        cin >> number;
        p.first = number;
        p.second = 1;
        
        while (!s.empty() && s.top().first < number)
        {
            cnt += s.top().second;
            s.pop();
        }
        if (!s.empty())
        {
            if (s.top().first == number)
            {
                cnt += s.top().second;
                s.top().second += 1;
                if (s.size() > 1)
                    cnt += 1;
                continue;
            }
            else
                cnt += 1;
        }
        s.push(p);
    }
    cout << cnt;
    return 0;
}