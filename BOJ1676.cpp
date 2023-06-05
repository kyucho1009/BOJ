#include <iostream>
using namespace std;

int main()
{
    int num;
    int result;

    cin >> num;
    result = (num / 5) + (num / 25) + (num / 125);
    cout << result;
}