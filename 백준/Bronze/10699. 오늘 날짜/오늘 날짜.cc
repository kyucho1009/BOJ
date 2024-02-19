#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);

    cout << t->tm_year + 1900 << "-"; // 년도
    if (t->tm_mon < 10)
        cout << 0 << t->tm_mon + 1 << "-"; // 월
    else
        cout << t->tm_mon + 1 << "-";
    cout << t->tm_mday; // 일
    return 0;
}