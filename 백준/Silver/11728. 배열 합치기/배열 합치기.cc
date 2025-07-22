#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr1[1000000];
int arr2[1000000];
int arr3[2000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr1[i];
    for (int i = 0; i < M; i++)
        cin >> arr2[i];
    int idx1;
    int idx2;
    idx1 = 0;
    idx2 = 0;
    for (int i = 0; i < N + M; i++)
    {
        if (idx1 >= N)
        {
            cout << arr2[idx2] << " ";
            idx2++;
        }
        else if (idx2 >= M)
        {
            cout << arr1[idx1] << " ";
            idx1++;
        }
        else if (arr1[idx1] <= arr2[idx2])
        {
            cout << arr1[idx1] << " ";
            idx1++;
        }
        else if (arr1[idx1] > arr2[idx2])
        {
            cout << arr2[idx2] << " ";
            idx2++;
        }
    }
    return 0;
}