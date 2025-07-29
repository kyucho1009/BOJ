#include <bits/stdc++.h>
using namespace std;

int sum;
int arr[9];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 9; i++)
        cin >> arr[i];
    int tmp[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};
    do
    {
        sum = 0;
        for (int i = 0; i < 9; i++)
            if (tmp[i] == 1)
                sum += arr[i];
        if (sum == 100)
        {
            for (int i = 0; i < 9; i++)
                if (tmp[i] == 1)
                    cout << arr[i] << "\n";
            break;
        }
    } while (next_permutation(tmp, tmp + 9));
    return 0;
}