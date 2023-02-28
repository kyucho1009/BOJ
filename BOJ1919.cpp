#include <iostream>
#include <string>
using namespace std;

int main()
{
    int sum = 0;
    int arr[26] = {0};
    string str1;
    string str2;

    cin >> str1;
    cin >> str2;

    for (auto c : str1)
    {
        arr[c - 'a']++;
    }
    for (auto c : str2)
    {
        arr[c - 'a']--;
    }
    for (auto i : arr)
    {
        sum += abs(i);
    }
    cout << sum;
    
    return 0;
}