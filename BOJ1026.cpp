#include <bits/stdc++.h>
using namespace std;

int N;
int A[51];
int B[51];

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    sort(A, A + N);
    sort(B, B + N, compare);
    int sum;
    sum = 0;
    for (int i = 0; i < N; i++)
        sum += A[i] * B[i];
    cout << sum;
    return 0;
}