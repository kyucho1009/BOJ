#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int num;
    int temp;
    int start;

    cnt = 0;
    start = 666;
    cin >> num;
    while (true)
    {
        temp = start;
        while (temp >= 666)
        {
            if (temp % 1000 == 666)
            {
                cnt++;
                break;
            }
            else
                temp /= 10;
        }
        if (cnt == num)
            break;
        else
            start++;
    }
    cout << start;
    return 0;
}