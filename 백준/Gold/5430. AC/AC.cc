#include <iostream>
#include <deque>
using namespace std;

int cnt;
int num;
int flag;
int element;
int test_case;
string order;
string array;
deque <int> dq;

int main()
{
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cnt = 0;
        flag = 1;
        element = 0;
        cin >> order >> num >> array;
        for (int j = 0; j < array.length(); j++)
        {
            if (array[j] == '[')
                continue;
            else if (array[j] == ',' || array[j] == ']')
            {
                if (element != 0)
                    dq.push_back(element);
                element = 0;
                continue;
            }
            else
            {
                element *= 10;
                element += array[j] -'0';
            }
        }
        for (auto j:order)
        {
            if (j == 'R')
                flag *= -1;
            else
            {
                if (dq.empty())
                {
                    cout << "error" << "\n";
                    dq.push_back(-1);
                    break;
                }
                if (flag == 1)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if (dq.back() == -1)
        {
            dq.clear();
            continue;
        }
        else if (dq.empty())
            cout << "[]" << "\n";
        else
        {
            cout << "[";
            while (!dq.empty())
            {
                if (flag == 1)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (dq.size() != 0)
                    cout << ",";
            }
            cout << "]" << "\n";
        }
        dq.clear();
    }
}