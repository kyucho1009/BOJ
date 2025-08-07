#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int ans;
int arr[300001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> arr[i];
    sort(arr, arr + M); // 보석 개수 정렬
    int st;
    int en;
    st = 1;
    en = arr[M - 1]; // 보석 최대개수는 최대 질투심 값과 같음
    while (st <= en)
    {
        int cnt;
        int mid;
        cnt = 0;
        mid = (st + en) / 2;        // 이분탐색을 위해 mid값 설정 이는 목표 질투심 값에 해당
        for (int i = 0; i < M; i++) // 위에서 설정한 질투심(mid) 값으로 수행
        {
            cnt += arr[i] / mid;   // 보석 개수를 질투심 값으로 나눠 몇명에게 나누어 줄지 계산
            if (arr[i] % mid != 0) // 나머지가 0이 아니라면 남은 보석을 한명 더 나눠줄 수 있음
                cnt++;
        }
        if (cnt <= N) // cnt 값이 아이들의 수보다 작다면 질투심 값이 작아져야하므로 en값 재설정
        {
            en = mid - 1;
            ans = mid;
        }
        else // cnt 값이 아이들의 수보다 크다면 질투심 값이 커져야하므로 st값 재설정
            st = mid + 1;
    }
    cout << ans;
    return 0;
}

/*
매개변수 탐색으로 풀어야함
보석 개수에 집중하는것이 아니라 질투심을 기준으로 잡고 문제에 접근해야한다(처음에 주어진 보석의 개수와 아이들 수에 집중해서 문제 감도 못잡았음)
질투심 최대/최소를 구하는 최적화 문제를 결정문제로 변환해 이분탐색 수행

Q. 33번 조건문에서 왜 en 값을 재설정해요? 어짜피 못받는 아이들이 있어도 된다고 문제에 제시되어 있는데
A. 우리는 질투심의 최솟값을 구해야하므로 답으로 가능한 더 작은 질투심 값이 존재할 수 있으므로 en을 재설정 후 없을 경우를 대비해서 ans에 mid값을 저장합니다
일단 mid값은 올바른 해답이 될 수 있으므로 저장하고 이후 더 작은 해답 탐색

Q. 38번 조건문에서 왜 mid값을 저장 안해요?
A. cnt 값이 아이들의 수보다 큰 경우는 절대 해답으로 나올 수 없는 질투심 값이므로 ans에 저장하지 않고 st값만 재설정 해줍니다
*/