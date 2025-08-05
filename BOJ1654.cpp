#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K;
int N;
int arr[10001];

bool solve(int len)
{
    long long ans;
    ans = 0;
    for (int i = 0; i < K; i++)
        ans += arr[i] / len;
    return ans >= N;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    long long sum;
    sum = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    long long st;
    long long en;
    st = 1;
    en = sum / N;
    while (st < en)
    {
        int mid;
        mid = (st + en + 1) / 2;
        if (solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
}