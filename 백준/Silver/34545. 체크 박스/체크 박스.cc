#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
bool arr[100001];
bool target[100001];
vector<int> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int diff;
    int check;
    int ischecked;
    diff = 0;
    check = 0;     // arr의 체크된 행의 개수
    ischecked = 0; // target의 체크된 행의 개수
    for (int i = 0; i < N; i++)
    {
        cin >> target[i];
        if (arr[i] != target[i])
            diff++;
        if (arr[i])
            check++;
        if (target[i])
            ischecked++;
    }
    V.push_back(diff);                        // 개별 체크 + 개별 해제
    V.push_back(1 + (N - ischecked));         // 전체 체크 + 개별 해제
    V.push_back((N - check) + 1 + ischecked); // 개별 체크 + 전체 해제 + 개별 체크
    V.push_back(2 + ischecked);               // 전체 체크 + 전체 해제 + 개별 체크
    sort(V.begin(), V.end());
    cout << V[0];
    return 0;
}