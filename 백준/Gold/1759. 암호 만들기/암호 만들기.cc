#include <bits/stdc++.h>
using namespace std;

int L;
int C;
char arr[15];
char alphabet[15];
bool isused[15];

void func(int num)
{
    if (num == L)
    {
        int vowel_cnt = 0;
        for (int i = 0; i < L; i++)
        {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                vowel_cnt++;
        }
        if (vowel_cnt > 0 && L - vowel_cnt > 1)
        {
            for (int i = 0; i < L; i++)
                cout << arr[i];
            cout << "\n";
            return;
        }
    }
    for (int i = 0; i < C; i++)
    {
        if (!isused[i] && arr[num - 1] < alphabet[i])
        {
            arr[num] = alphabet[i];
            isused[i] = 1;
            func(num + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> alphabet[i];
    sort(alphabet, alphabet + C);
    func(0);
    return 0;
}