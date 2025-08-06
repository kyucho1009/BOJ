#include <bits/stdc++.h>
using namespace std;

int A;
int B;
int arr1[500001];
int arr2[500001];
vector<int> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    int num;
    for (int i = 0; i < A; i++)
        cin >> arr1[i];
    sort(arr1, arr1 + A);
    for (int i = 0; i < B; i++)
        cin >> arr2[i];
    sort(arr2, arr2 + B);
    for (int i = 0; i < A; i++)
    {
        if (!binary_search(arr2, arr2 + B, arr1[i]))
            V.push_back(arr1[i]);
    }
    if (V.size() == 0)
        cout << 0;
    else
    {
        cout << V.size() << "\n";
        for (auto k : V)
            cout << k << " ";
    }
    return 0;
}