#include <bits/stdc++.h>
using namespace std;

int N;
int sum;
int arr[100001];
pair<int, int> cur;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    sum = 2000000000;
    for (int i = 0; i < N - 1; i++)
    {
        int idx;
        int target;
        target = -arr[i];
        idx = lower_bound(arr + i + 1, arr + N, target) - arr;
        if (idx < N) // lower_bound의 반환값이 N인 경우 제외(타겟 이상의 값이 존재하지 않을경우 end값 반환으로 N값이 반환됨)
        {
            if (sum > abs(arr[i] + arr[idx]))
            {
                sum = abs(arr[i] + arr[idx]);
                cur = {arr[i], arr[idx]};
            }
        }
        if (idx - 1 > i) // idx - 1값이 i 이하인 경우 제외(같은 수가 2개 들어가는 경우 제외)
        {
            if (sum > abs(arr[i] + arr[idx - 1]))
            {
                sum = abs(arr[i] + arr[idx - 1]);
                cur = {arr[i], arr[idx - 1]};
            }
        }
    }
    cout << cur.first << " " << cur.second;
    return 0;
}

/*
먼저 문제를 살펴보면 입력받는 값의 개수는 10만으로 모든 경우를 따지면 O(N^2)로 시간초과 발생
그렇기에 이분탐색을 사용해 시간복잡도 O(NlogN)으로 수행

먼저 입력받은 배열을 정렬 후
반복문을 이용해 N-1개의 수를 차례로 확인해가며 해당 수의 음의 값에 가장 가까운 수를 찾는 방법입니다

문제의 목적은 두 수의 합이 0에 가장 가까운 수의 조합을 찾는것이므로
반복문으로 배열을 탐색하며 해당 수의 음수를 타겟으로 lower_bound를 사용시 타겟 이상의 수에 해당하는 인덱스를 반환 받습니다
다른말로 하면 lower_bound는 타겟에 해당하는 수가 들어가야할 위치를 반환해주는것입니다
그렇다면 반환값이 카리키는 인덱스에 해당하는 값은 타겟 값 이상의 가장 작은 값
바로 아래 인덱스가 가리키는 값은 타겟 미만 값 중 가장 큰 값
이렇게 타겟에 가장 가까운 두 수를 얻을 수 있습니다.

이 두 수를 이용해 0에 가장 가까운 조합을 찾아낼 수 있습니다
*/