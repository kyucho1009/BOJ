#include <bits/stdc++.h>
using namespace std;

int n;
int cut;
int level;
double ans;
vector<int> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> level;
        V.push_back(level);
    }
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    cut = round(n * 0.15);
    sort(V.begin(), V.end());
    for (int i = cut; i < n - cut; i++)
        ans += V[i];
    cout << round(ans / (n - cut * 2));
    return 0;
}
/*
주의점
n이 0일 경우 예외처리
절사평균을 만들기 위해 반복문 안에서 vector의 요소들을 자르는 함수를 사용해 시간초과
erase 함수는 O(N)의 시간복잡도를 가지고 for문 안에서 실행하므로 O(N^2) 시간 초과 발생
*/