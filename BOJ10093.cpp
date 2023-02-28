#include <iostream>
using namespace std;

void swap(long long *a, long long *b)
{
    long long temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    long long min;
    long long max;
    int length;

    cin >> min >> max;
    if (min > max)
        swap(min, max);
    if (min == max)
        cout << 0 << "\n";
    else
    {
        length = max - min - 1;
        cout << length << "\n";
        for (long long i = min + 1; i < max; i++)
        {
            cout << i << " ";
        }
    }

    return 0;
}