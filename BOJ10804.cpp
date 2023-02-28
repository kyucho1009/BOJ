#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void tab_rev(int start, int end, int *arr)
{
    int length;

    length = (end - start + 1) / 2;
    while (length--)
    {
        swap(&arr[start++], &arr[end--]);
    }
}

int main()
{
    int start = 0;
    int end = 0;
    int arr[21] = {0};

    for (int i = 1; i < 21; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> start >> end;
        tab_rev(start, end, arr);
    }
    for (int i = 1; i < 21; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}