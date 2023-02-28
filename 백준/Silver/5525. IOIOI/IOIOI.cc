#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 0;
    int cnt = 0;
    int flag = 0;
    int length = 0;
    string str;

    cin >> n;
    cin >> length;
    cin >> str;

    for (int i = 0; i < length; i++)
    {
        flag = 0;
        if (str[i] == 'I')
        {
            for (int j = 0; j < 2 * n + 1; j++)
            {
                if (j % 2 == 0 && str[i + j] == 'I')
                    continue;
                else if (j % 2 == 1 && str[i + j] == 'O')
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}