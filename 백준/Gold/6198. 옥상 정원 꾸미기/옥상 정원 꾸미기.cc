#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    int height;
    long long sum;
    stack <int> s;

    sum = 0;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> height;
        if (i == 0)
            s.push(height);
        else
        {
            while (s.size() != 0 && s.top() <= height)
                s.pop();
            sum += s.size();
            s.push(height);
        }
    }
    cout << sum;
}