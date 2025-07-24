#include <bits/stdc++.h>
using namespace std;

int cnt;
int N, M;
int left_element;
int right_element;
int idx;
deque<int> dq;

void func2()
{
    dq.push_back(dq.front());
    dq.pop_front();
}

void func3()
{
    dq.push_front(dq.back());
    dq.pop_back();
}

int main()
{
    cnt = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    for (int i = 0; i < M; i++)
    {
        cin >> idx;
        if (dq.front() == idx)
            dq.pop_front();
        else
        {
            for (int j = 0; j < dq.size(); j++)
            {
                if (dq[j] == idx)
                {
                    left_element = j;
                    right_element = dq.size() - j;
                    break;
                }
            }
            if (left_element < right_element)
            {
                while (left_element--)
                {
                    func2();
                    cnt++;
                }
                dq.pop_front();
            }
            else
            {
                while (right_element--)
                {
                    func3();
                    cnt++;
                }
                dq.pop_front();
            }
        }
    }
    cout << cnt;
    return 0;
}