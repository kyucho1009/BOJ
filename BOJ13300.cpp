#include <iostream>
using namespace std;

int main()
{
    int student_num = 0;
    int member_num = 0;
    int gender = -1;
    int grade = 0;
    int room = 0;
    int boy[7] = {0};
    int girl[7] = {0};

    cin >> student_num >> member_num;
    for (int i = 0; i < student_num; i++)
    {
        cin >> gender >> grade;
        if (gender == 0)
            girl[grade] += 1;
        else
            boy[grade] += 1;
    }
    for (int i = 1; i < 7; i++)
    {
        if (girl[i] != 0 && girl[i] % member_num != 0)
            room += girl[i] / member_num + 1;
        else if (girl[i] != 0 && girl[i] % member_num == 0)
            room += girl[i] / member_num;
        else
            ;
        if (boy[i] != 0 && boy[i] % member_num != 0)
            room += boy[i] / member_num + 1;
        else if (boy[i] != 0 && boy[i] % member_num == 0)
            room += boy[i] / member_num;
        else
            ;
    }
    cout << room;
    return 0;
}