#include <iostream>
using namespace std;

int factorial(int num)
{
    int result;

    result = 1;
    if (num == 0 || num == 1)
        return 1;
    else
    {
        result = factorial(num - 1);
        return(result * num);
    }
}

int main()
{
    int num;
    int result;

    cin >> num;
    result = factorial(num);
    cout << result;
}