#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int x;
int y;
int d;
int g;
bool board[102][102];
vector<pair<int, int>> V;

void rotate()
{
    vector<pair<int, int>> NV;
    pair<int, int> point = V.back();
    for (auto i = V.rbegin() + 1; i != V.rend(); ++i)
    {
        int nx = point.X - (i->Y - point.Y);
        int ny = point.Y + (i->X - point.X);
        NV.push_back({nx, ny});
    }
    V.insert(V.end(), NV.begin(), NV.end());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> x >> y >> d >> g;
        V.clear();
        V.push_back({x, y});
        if (d == 0)
            V.push_back({x + 1, y});
        else if (d == 1)
            V.push_back({x, y - 1});
        else if (d == 2)
            V.push_back({x - 1, y});
        else if (d == 3)
            V.push_back({x, y + 1});
        while (g--)
            rotate();
        for (auto i : V)
            board[i.X][i.Y] = 1;
    }
    int cnt;
    cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                cnt++;
        }
    }
    cout << cnt;
}

/*
해결방법
1. 시작좌표와 방향을 입력받아 0세대 커브 좌표를 저장한다
2. 입력받은 세대 수 만큼 시계방향 90도 회전
3. 커브를 구성하는 모든 좌표를 2차원 배열에 저장
4. 2차원 배열을 탐색하며 한 좌표를 기준으로 우측, 우측아래 대각선, 아래 3개의 좌표와 함께 값이 참이면 해답 1증가
5. 해답 출력

이문제를 해결하기 위한 접근법은 간단하다
0세대 커브를 만들고 마지막 좌표를 기준점으로 뒤에서부터 모든 좌표의 점을 시계방향으로 90도 회전 후 좌표를 저장하는것이다
말이 어려우니 예제1번으로 보여주겠다

처음으로 입력받는 커브의 정보는 3, 3, 0, 1이다
(3, 3)좌표에서 0방향으로 시작하므로 0세대 커브는 (3, 3)과 (4, 3)를 이어주는 선분이다
(3, 3), (4, 3) 좌표 저장

마지막 좌표인 (4, 3)를 기준으로 (3, 3)좌표 시계방향으로 90도 회전
(3, 3) -> (4, 2) *아래 수식 참고
90도 회전한 좌표를 저장하면
(3, 3), (4, 3), (4, 2)

다시 반복하면
마지막좌표인 (4, 2)를 기준점으로 설정
뒤에서부터 회전하면
(4, 3) -> (3, 2) *아래 수식 참고
(3, 3) -> (3, 1) *아래 수식 참고
새롭게 얻은 좌표들을 저장하면
(3, 3), (4, 3), (4, 2), (3, 2), (3, 1)

위와 같은 방법으로 커브를 계속해서 만들어 나갈 수 있다

이렇게 얻은 커브를 구성하는 좌표들을 2차원 배열에 저장 후
배열을 탐색하며 해답을 얻으면 된다

* 한 점을 기준으로 한점을 90도 회전하는 수식
(x, y)를 (a, b)를 기준으로 회전
x' = a - (y - b), y' = b + (x - a)
*/