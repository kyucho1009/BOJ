#include <bits/stdc++.h>
using namespace std;

int N;
int M;
long long cnt;
long long tmp[100001];
long long arr[1000001];
long long sum[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sum[0] = arr[0];
    for (int i = 1; i < N; i++)
        sum[i] = arr[i] + sum[i - 1];
    for (int i = 0; i < N; i++)
        tmp[sum[i] % M]++;
    for (int i = 0; i < M; i++)
        cnt += tmp[i] * (tmp[i] - 1) / 2;
    cnt += tmp[0];
    cout << cnt;
    return 0;
}
/*
- 문제 접근법
누적합 배열을 생성 후 누적합 배열에 M으로 나눈 나머지 값으로 치환하여 저장한다
예제 입력1의 경우 1 0 0 1 0으로 저장될 것이다
여기서 나머지의 값이 같은 것끼리의 조합으로 구간을 구하면 된다
나머지가 같은것끼리 구간의 누적합은 나머지가 같아 해당 구간을 M으로 나눈 나머지는 0이된다
*/