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

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> length;
    cin >> str;

    for (int i = 0; i < length; i++)
    {
        int k = 0;
        if (str[i] == 'I')
        {
            while (str[i + 1] == 'O' && str[i + 2] == 'I')
            {
                k++;
                if (k == n)
                {
                    k--;
                    cnt++;
                }
                i += 2;
            }
        }
    }
    cout << cnt;

    return 0;
}