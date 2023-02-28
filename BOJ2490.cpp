#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int arr[4];

    for (int i = 0; i < 3; i++)
    {
        cnt = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> arr[j];
            if (arr[j] == 0)
                cnt++;
        }
        if (cnt == 1)
            cout << "A" << "\n";
        else if (cnt == 2)
            cout << "B" << "\n";
        else if (cnt == 3)
            cout << "C" << "\n";
        else if (cnt == 4)
            cout << "D" << "\n";
        else if (cnt == 0)
            cout << "E" << "\n";
    }
    return 0;
}