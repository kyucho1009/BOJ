#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    int num = 0;
    char command = 0;
    string str;
    list <char> l;
    list <char>::iterator cursor;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        l.clear();
        cin >> str;
        cursor = l.begin();
        for (auto c : str)
        {
            if (c == '<')
            {
                if (cursor != l.begin())
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != l.end())
                    cursor++;
            }
            else if (c == '-')
            {
                if (cursor != l.begin())
                {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            }
            else
            {
                l.insert(cursor, c);
            }
        }
        for (auto c : l)
            cout << c;
        cout << "\n";
    }

    return 0;
}

/*
계속해서 런타임에러가 발생하는 문제가 있었지만 해당 문제는 잘못된 알고리즘의 사용이 아닌 잘못된 메모리를 건드려 런타임에러가 발생한 것이다.
iterator를 반복문엣서 초기화 시켜서 잘못된 메모리 침범 문제를 해결함
*/