#include <bits/stdc++.h>
using namespace std;

int T;
int K;
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        priority_queue<long long, vector<long long>, greater<long long>> PQ; // 케이스별로 초기화를 위해 반복문 안에서 선언
        cin >> K;
        int num;
        for (int i = 0; i < K; i++)
        {
            cin >> num;
            PQ.push(num);
        }
        long long sum;
        ans = 0;
        while (PQ.size() != 1) // 파일이 1개가 될때까지
        {
            sum = 0;
            sum += PQ.top(); // 맨 앞 파일값 더하기
            PQ.pop();        // 맨 앞 파일 삭제
            sum += PQ.top(); // 맨 앞 파일값 더하기
            PQ.pop();        // 맨 앞 파일 삭제
            PQ.push(sum);    // 합친 파일 PQ에 넣어주기
            ans += sum;      // 합친 값 저장
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
해결법은 정말 간단하다

파일을 합칠때마다 생기는 비용의 합을 구하므로
큰 파일을 미리 합친다면 계속해서 더 큰 파일을 합치게 되므로 작은것부터 합치는게 중요하다

우선순위 큐를 사용해서 두 파일을 합치고 합친 파일 우선순위 큐에 넣어
계속해서 작은 파일 순으로 합치도록 설계
*/