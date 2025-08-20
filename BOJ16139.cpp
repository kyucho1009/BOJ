#include <bits/stdc++.h>
using namespace std;

int q;
int st;
int en;
char alpha;
int arr[26][200001];
string S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    cin >> q;
    for (int i = 1; i <= S.length(); i++)
    {
        int a;
        a = S[i - 1] - 97;
        for (int j = 0; j < 26; j++)
        {
            if (a == j)
                arr[j][i] = arr[j][i - 1] + 1;
            else
                arr[j][i] = arr[j][i - 1];
        }
    }
    while (q--)
    {
        cin >> alpha >> st >> en;
        cout << arr[alpha - 97][en + 1] - arr[alpha - 97][st] << "\n";
    }
    return 0;
}