#include <iostream>
#include <vector>
using namespace std;

void put_nbr(int num, vector <int> &arr)
{
    if (num >= 10)
        put_nbr(num / 10, arr);
    arr.push_back(num % 10);
}

int main()
{
    int i = 0;
    int cnt = 0;
    int num = 0;
    int index = 0;
    int numbers[4] = {2, 0, 2, 3};
    vector <int> arr;

    cin >> num;
    if (num / 2023 == 0)
    {
        cout << 0;
        return 0;
    }
    else
    {
        i = 2023;
        cnt = 0;
        while (i <= num)
        {
            arr.clear();
            index = 0;
            put_nbr(i, arr);
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j] == numbers[index] && index < 4)
                {
                    index++;
                }
            }
            if (index == 4)
                cnt++;
            i++;
        }
    }
    cout << cnt;
    return 0;
}