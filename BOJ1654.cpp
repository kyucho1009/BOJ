#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int after;
    int before;
    long long ans;
    long long sum;
    long long low;
    long long mid;
    long long high;
    vector<int> len(10000);

    ans = 0;
    sum = 0;                         // sum 초기화
    cin >> before >> after;          // 조건 입력
    for (int i = 0; i < before; i++) // 테스트 케이스 입력
    {
        cin >> len[i];
        sum += len[i]; // 모든 랜 길이의 합
    }
    low = 1;            // 최소값 설정
    high = sum / after; // 최댓갑 설정
    mid = (low + high) / 2;
    while (low <= high)
    {
        sum = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < before; i++)
            sum += len[i] / mid;
        if (sum >= after)
        {
            low = mid + 1;
            ans = max(ans, mid);
        }
        else
            high = mid - 1;
    }
    cout << ans;
    return 0;
}