#include <bits/stdc++.h>
using namespace std;

int N;
int L;
int ans;
int board[100][100];

bool check(vector<int> &line)
{
    int idx;
    int cnt;
    idx = 0;
    cnt = 1;
    while (idx < N - 1)
    {
        if (abs(line[idx] - line[idx + 1]) > 1)
            return 0;
        if (line[idx] == line[idx + 1])
        {
            cnt++;
            idx++;
        }
        else if (line[idx] < line[idx + 1])
        {
            if (cnt < L)
                return 0;
            cnt = 1;
            idx++;
        }
        else
        {
            if (idx + 1 >= N)
                return 0;
            for (int i = idx + 1; i < idx + L; i++)
                if (line[i] != line[i + 1])
                    return 0;
            idx += L;
            cnt = 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    // 가로 줄 확인
    for (int i = 0; i < N; i++)
    {
        vector<int> line;
        for (int j = 0; j < N; j++)
            line.push_back(board[i][j]);
        ans += check(line);
    }
    // 세로 줄 확인
    for (int i = 0; i < N; i++)
    {
        vector<int> line;
        for (int j = 0; j < N; j++)
            line.push_back(board[j][i]);
        ans += check(line);
    }
    cout << ans;
}

/*
한 변의 길이: N
경사로의 길이: L
전체 길의 개수: 2N
가능한 길의 개수: ?

불가능한 길의 조건
높이가 한번에 2이상 증감 제외

*/