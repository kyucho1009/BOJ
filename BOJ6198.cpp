#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num;
    int max;
    int height;
    stack <int> index;
    stack <int> building;

    max = 0;
    cin >> num;
    int sum[num];
    for (int i = 0; i < num; i++)
        sum[i] = num - i - 1;
    for (int i = 0; i < num; i++)
    {
        cin >> height;
        building.push(height);
        sum[building.size() - 1];
    }

    return 0;
}

//10 3 7 4 12 1