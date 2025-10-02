#include <bits/stdc++.h>
using namespace std;

int N;
bool ans;
pair<int, int> sn;
int arr[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ans = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                sn = {i, j};
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && ((sn.first + sn.second) % 2 == (i + j) % 2))
                ans = false;
        }
    }
    if (ans)
        cout << "Lena";
    else
        cout << "Kiriya";
    return 0;
}