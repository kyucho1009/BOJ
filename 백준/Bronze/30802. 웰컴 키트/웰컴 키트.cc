#include <iostream>
using namespace std;

int main()
{
    int attendance;
    int size[6];
    int t_bundle;
    int p_bundle;
    int sum;

    sum = 0;
    cin >> attendance;
    for (int i = 0; i < 6; i++)
        cin >> size[i];
    cin >> t_bundle >> p_bundle;

    for (int i = 0; i < 6; i++)
    {
        if (size[i] % t_bundle == 0)
            sum += size[i] / t_bundle;
        else
            sum += size[i] / t_bundle + 1;
    }
    cout << sum << "\n";
    cout << attendance / p_bundle << " " << attendance % p_bundle;
    return 0;
}