#include <bits/stdc++.h>
using namespace std;

int N;
int M;
bool arr[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 2000001; i++)
        arr[i] = 1;
    arr[1] = false;
    for (int i = 2; i < 2000001; i++)
    {
        if (arr[i])
        {
            for (int j = 2; j * i <= 2000001; j++)
                arr[i * j] = false;
        }
    }
    if (M % 2 == 0)
    {
        int a;
        a = 4;
        while (N--)
        {
            cout << a << " ";
            a += M;
        }
    }
    else
    {
        int num;
        bool ispossible;
        for (int a = 1; a <= 2000001; a++)
        {
            ispossible = true;
            if (a % 2 == 1) // 첫 항이 홀수
            {
                for (int i = 1; i <= N;)
                {
                    if (arr[a + M * (i - 1)] == 1)
                    {
                        ispossible = false;
                        break;
                    }
                    i += 2;
                }
            }
            else // 첫 항이 짝수
            {
                for (int i = 2; i <= N;)
                {
                    if (arr[a + M * (i - 1)] == 1)
                    {
                        ispossible = false;
                        break;
                    }
                    i += 2;
                }
            }
            if (ispossible)
            {
                num = a;
                break;
            }
        }
        while (N--)
        {
            cout << num << " ";
            num += M;
        }
    }
    return 0;
}
/*
공차가 짝수인 경우는 항상 통과
공차가 홀수인 경우가 문제
그냥 딱 봤을때 구분하는 방법이 있을듯
첫항이 짝수에 공차가 홀수인 경우
첫항이 홀수에 공차가 홀수인 경우
*/