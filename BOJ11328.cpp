#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 0;
    int flag = 0;
    int arr[26] = {0};
    string dest;
    string str;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        flag = 0;
        fill_n(arr, 26, 0);
        cin >> dest >> str;
        for (auto c : dest)
        {
            arr[c - 'a']++;
        }
        for (auto c : str)
        {
            arr[c - 'a']--;
        }
        for (auto c : arr)
        {
            if (c != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "Possible" << "\n";
        else
            cout << "Impossible" << "\n";
    }
    
    return 0;
}