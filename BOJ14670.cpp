#include <bits/stdc++.h>
using namespace std;

int N;
int R;
map<int, int> M;
map<int, int> L;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int ME;
    int MN;
    while (N--)
    {
        cin >> ME >> MN;
        M[ME] = MN;
    }
    cin >> R;
    int L;
    int S;
    while (R--)
    {
        cin >> L;
        vector<int> V;
        for (int i = 0; i < L; i++)
        {
            cin >> S;
            if (M.find(S) != M.end())
                V.push_back(S);
        }
        if (V.size() == L)
        {
            for (auto k : V)
                cout << M[k] << " ";
        }
        else
            cout << "YOU DIED";
        cout << "\n";
    }
    return 0;
}