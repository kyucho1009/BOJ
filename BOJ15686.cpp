#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int board[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                house.push_back({i, j});
            else if (board[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    vector<int> chicken_dist;
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - M, 0);
    do
    {
        int dist = 0;
        for (auto h : house)
        {
            int temp = 2147483647;
            for (int i = 0; i < chicken.size(); i++)
            {
                if (brute[i] == 0)
                    continue;
                temp = min(temp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            dist += temp;
        }
        chicken_dist.push_back(dist);
    } while (next_permutation(brute.begin(), brute.end()));
    cout << *min_element(chicken_dist.begin(), chicken_dist.end());
}