#include <bits/stdc++.h>
using namespace std;

int N, M; // 나무의 수, 집에 가져갈 나무의 길이
int height;
vector<int> v(N);

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> height;
        v.push_back(height);
    }

    sort(v.begin(), v.end());

    int top = v.back();
    long long mid;
    long long sum;
    int bottom = 0;
    while (1)
    {
        sum = 0;
        mid = (top + bottom) / 2;
        for (auto i : v)
        {
            if (i > mid)
                sum += i - mid;
        }
        if (M == sum || bottom > top)
        {
            cout << mid;
            break;
        }

        else if (M > sum)
            top = mid - 1;
        else if (M < sum)
            bottom = mid + 1;
    }

    return 0;
}