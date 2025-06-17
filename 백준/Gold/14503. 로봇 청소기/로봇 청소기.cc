#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int R;
int C;
int dir;
int cnt;
int board[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> R >> C >> dir;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    while (true)
    {
        // 청소되지 않은 경우 청소
        if (board[R][C] == 0)
            cnt++;
        board[R][C] = -1; // 청소 표시
        bool clean = true;
        for (int i = 0; i < 4; i++) // 주변 4칸 확인
        {
            dir = (dir + 3) % 4;                      // 반시계 방향 회전
            if (board[R + dx[dir]][C + dy[dir]] == 0) // 청소되지 않은곳 발견
            {
                R += dx[dir]; // 회전한 방향으로 전진
                C += dy[dir];
                clean = false; // 주변 4칸 전부 청소되지 않았음
                break;
            }
        }
        if (!clean)                               // 주변 4칸 전부 청소X
            continue;                             // 다시 위로 돌아가서 청소
        if (board[R - dx[dir]][C - dy[dir]] == 1) // 주변 4칸 전부 청소, 뒤에 벽O
            break;                                // 로봇 정지
        R -= dx[dir];                             // 후진
        C -= dy[dir];
    }
    cout << cnt; // 결과 출력
}