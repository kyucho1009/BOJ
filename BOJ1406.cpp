#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    int num;
    char command;
    char character;
    string str;
    list <char> l;
    auto cursor = l.end();
    
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        l.push_back(str[i]);
    }

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> command;
        if (command == 'L' && cursor != l.begin())
            cursor--;
        else if (command == 'D' && cursor != l.end())
            cursor++;
        else if (command == 'B' && cursor != l.begin())
        {
            cursor--;
            cursor = l.erase(cursor);
        }
        else if (command == 'P')
        {
            cin >> character;
            l.insert(cursor, character);
        }
    }
    for (auto i : l)
    {
        cout << i;
    }
    return 0;
}