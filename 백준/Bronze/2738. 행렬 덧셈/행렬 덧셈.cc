#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr1[100][100];
int arr2[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr1[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr2[i][j];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << arr1[i][j] + arr2[i][j] << " ";
        cout << "\n";
    }
}