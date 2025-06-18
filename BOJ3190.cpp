#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int K;
int L;
int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int>> snake;  // front()가 뱀의 머리, back()이 뱀의 꼬리로 생각
queue<pair<int, char>> order; // 이동 방향 변경 명령 저장

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K; // 보드의 크기, 사과의 개수 입력
    int x;
    int y;
    for (int i = 0; i < K; i++) // 사과 위치 저장
    {
        cin >> x >> y;
        board[x][y] = 1;
    }
    cin >> L; // 방향 전환 횟수
    int when;
    char where;
    for (int i = 0; i < L; i++) // 방향 전환 명령 저장
    {
        cin >> when >> where;
        order.push({when, where});
    }
    int dir = 1;              // 현재 이동 방향
    int time = 0;             // 현재 시간
    snake.push_front({1, 1}); // 0, 0에 뱀의 머리 지정
    while (true)
    {
        time++; // 시간 증가
        auto head = snake.front();

        int nx = head.X + dx[dir]; // 다음 뱀의 머리 위치 X좌표
        int ny = head.Y + dy[dir]; // 다음 뱀의 머리 위치 Y좌표

        if (nx < 1 || nx > N || ny < 1 || ny > N) // 다음 뱀의 머리 위치가 벽이면 종료
            break;

        bool stop = false;
        for (auto pos : snake)
        {
            if (pos.X == nx && pos.Y == ny) // 다음 뱀의 머리 위치가 몸통이면 종료
                stop = true;
        }
        if (stop)
            break;

        if (board[nx][ny] == 1) // 뱀의 다음 머리 위치에 사과가 있으면 머리는 이동하고 꼬리는 그대로
        {
            board[nx][ny] = 0;          // 보드에서 사과 삭제
            snake.push_front({nx, ny}); // 뱀의 머리 위치 변경
        }
        else // 뱀의 다음 머리 위치에 사과가 없으면 머리 이동하고 꼬리도 이동
        {
            snake.push_front({nx, ny}); // 뱀의 머리 위치 변경
            snake.pop_back();           // 뱀의 꼬리 위치 변경
        }

        if (time == order.front().X) // 이동 방향 변경 시간이 되면 이동 방향 변경
        {
            if (order.front().Y == 'D') // 이동 방향 변경 명령이 D면 오른쪽으로 방향 전환
                dir = (dir + 3) % 4;
            else // 이동 방향 명령이 L이면 왼쪽으로 방향 전환
                dir = (dir + 1) % 4;
            order.pop();
        }
    }
    cout << time; // 결과 출력
}