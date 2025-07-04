#include <bits/stdc++.h>
using namespace std;

int N;
int sum;
int ans;
int S[20][20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += S[i][j];
    ans = 2147483647;
    vector<int> team(N);
    fill(team.begin() + N / 2, team.end(), 1);
    do
    {
        int diff;
        diff = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (team[i] != team[j])
                    continue;
                if (team[i] == 0)
                    diff += (S[i][j] + S[j][i]);
                else
                    diff -= (S[i][j] + S[j][i]);
            }
        }
        ans = min(ans, abs(diff));
    } while (next_permutation(team.begin(), team.end()));
    cout << ans;
    return 0;
}