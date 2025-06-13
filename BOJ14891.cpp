#include <bits/stdc++.h>
using namespace std;

int num;
int dir;
int ans;
int test_case;
string gear[5];
vector<pair<int, int>> check;

void clockwise(int num, int dir)
{
    if (dir == 1)
    {
        string temp = gear[num].substr(0, 7);
        gear[num].erase(0, 7);
        gear[num].append(temp);
    }
    else
    {
        char temp = gear[num][0];
        gear[num].erase(0, 1);
        gear[num].push_back(temp);
    }
}

void rotate(int num, int dir)
{
    check.clear();
    if (num == 1)
    {
        check.push_back({num, dir});
        if (gear[num][2] != gear[num + 1][6])
        {
            check.push_back({num + 1, -dir});
            if (gear[num + 1][2] != gear[num + 2][6])
            {
                check.push_back({num + 2, dir});
                if (gear[num + 2][2] != gear[num + 3][6])
                    check.push_back({num + 3, -dir});
            }
        }
    }
    else if (num == 2)
    {
        check.push_back({num, dir});
        if (gear[num - 1][2] != gear[num][6])
            check.push_back({num - 1, -dir});
        if (gear[num][2] != gear[num + 1][6])
        {
            check.push_back({num + 1, -dir});
            if (gear[num + 1][2] != gear[num + 2][6])
                check.push_back({num + 2, dir});
        }
    }
    else if (num == 3)
    {
        check.push_back({num, dir});
        if (gear[num - 1][2] != gear[num][6])
        {
            check.push_back({num - 1, -dir});
            if (gear[num - 2][2] != gear[num - 1][6])
                check.push_back({num - 2, dir});
        }
        if (gear[num][2] != gear[num + 1][6])
            check.push_back({num + 1, -dir});
    }
    else
    {
        check.push_back({num, dir});
        if (gear[num - 1][2] != gear[num][6])
        {
            check.push_back({num - 1, -dir});
            if (gear[num - 2][2] != gear[num - 1][6])
            {
                check.push_back({num - 2, dir});
                if (gear[num - 3][2] != gear[num - 2][6])
                    check.push_back({num - 3, -dir});
            }
        }
    }
    for (auto k : check)
        clockwise(k.first, k.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < 5; i++)
        cin >> gear[i];
    cin >> test_case;
    while (test_case--)
    {
        cin >> num >> dir;
        rotate(num, dir);
    }
    for (int i = 1; i < 5; i++)
        if (gear[i][0] == '1')
            ans += pow(2, i - 1);
    cout << ans;
    return 0;
}