#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    int num = 0;
    char command;
    string str;
    list <char> l;
    auto cursor = l.end();

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        l.clear();
        cin >> str;
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
}