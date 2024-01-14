#include <iostream>
using namespace std;

int main()
{
    int row;
    int col;
    int inven;
    int height;
    int map[500][500];

    cin >> row >> col >> inven;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> height;
            map[i][j] = height;
        }
    }
    /*=================complete=================*/
}