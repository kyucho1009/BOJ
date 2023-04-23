#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size;
    int number;
    stack <int> s;

    cin >> size;

    int arr[size];

    for(int idx = 0; idx < size; idx++)
    {
        cin >> number;
        arr[idx] = number;

        if (s.size() == 0)
            s.push(idx);
        else
        {
            if (arr[s.top()] > number)
                s.push(idx);
            else
            {
                while (s.size() != 0 && arr[s.top()] < number)
                {
                    arr[s.top()] = number;
                    s.pop();
                }
                s.push(idx);
            }
        }
    }
    while (s.size() != 0)
    {
        arr[s.top()] = -1;
        s.pop();
    }
    for (auto answer:arr)
        cout << answer << " ";
    return 0;
}