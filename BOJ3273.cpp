#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num = 0;
    int cnt = 0;
    int target = 0;

    cin >> num;
    int left = 0;
    int right = num - 1;
    vector <int> arr(num);

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> target;
    while (left < right)
    {
        if (arr[left] + arr[right]  < target)
            left++;
        else if (arr[left] + arr[right] > target)
            right--;
        else
        {
            cnt++;
            left++;
        }
    }
    cout << cnt;
    return 0;
}