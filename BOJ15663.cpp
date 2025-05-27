#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[10];
int digit[10];
bool isused[10];

void func(int num)
{
    if (num == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (!isused[i] && tmp != digit[i])
        {
            arr[num] = digit[i];
            isused[i] = 1;
            tmp = arr[num];
            func(num + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> digit[i];
    sort(digit, digit + N);
    func(0);
    return 0;
}

/*
- 첫 풀이
중복된 입력 수에서 문제가 발생하므로 unique 함수를 이용해 중복된 수를 없애고 수열 생성
- 문제점
중복된 수를 제거하면 특정 수열이 만들어지지 않는 문제점 발생

- 새로운 풀이
이전 수열과 이번 수열을 비교해 같으면 출력 X (더 나은 풀이 존재)

- 더 나은 풀이
이전 수열을 따로 저장해서 수열 전체를 비교하는 불필요한 연산 제거하고
하나의 변수를 생성해 이전 수열에 넣은 수를 저장
func(0) -> 이전 출력에서 0번쨰 자릿수를 저장 하고 이번 0번째 자릿수와 비교
    0번째 자릿수에 같은 수가 다시 들어온다면 또 다시 같은 수열들이 출력될것이다
func(1) -> 이전 출력에서 1번쨰 자릿수를 저장 하고 이번 1번째 자릿수와 비교
    1번째 자릿수에 같은 수가 다시 들어온다면 또 다시 같은 수열들이 출력될것이다
func(1) -> 이전 출력에서 2번쨰 자릿수를 저장 하고 이번 2번째 자릿수와 비교
    2번째 자릿수에 같은 수가 다시 들어온다면 또 다시 같은 수열들이 출력될것이다
...
이렇게 반복되어 같은 수열의 출력을 막는다
*/