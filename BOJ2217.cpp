#include <bits/stdc++.h>
using namespace std;

int N;
int rope[100001];
int weight[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rope[i];
    sort(rope, rope + N);
    for (int i = 0; i < N; i++)
        weight[i] = (N - i) * rope[i];
    cout << *max_element(weight, weight + N);
    return 0;
}