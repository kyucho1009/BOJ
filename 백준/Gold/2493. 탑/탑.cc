#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num = 0;
    int cnt = 0;
    int height = 0;
    stack <int> tower;
    stack <int> index;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cin >> height;

        while (!tower.empty() && height > tower.top())
        {
            tower.pop();
            index.pop();
        }

        if (tower.size() == 0)
            cout << 0 << " ";
        else
            cout << index.top() << " ";
        tower.push(height);
        index.push(i);
    }

    return 0;
}