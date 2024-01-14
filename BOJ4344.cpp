#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int sum;
    int score;
    int student;
    int testCase;
    double avg;
    double result;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cnt = 0;
        sum = 0;
        cin >> student;
        int *scoreBoard = new int[student];
        for (int j = 0; j < student; j++)
        {
            cin >> score;
            sum += score;
            scoreBoard[j] = score;
        }
        avg = (double)sum / student;
        for (int j = 0; j < student; j++)
        {
            if (scoreBoard[j] > avg)
                cnt++;
        }
        result = (double)cnt / student * 100;
        printf("%.3f%%", result);
    }
    return 0;
}