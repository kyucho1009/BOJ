#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int main(void) {
    int N , M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int card;
        cin >> card;
        v.push_back(card);
    }
    int sum = 0;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                if(v[i] + v[j] +v[k] <= M && sum < v[i] + v[j] + v[k]) {
                    sum = v[i] + v[j] + v[k];
                }
            }
        }
    }
    cout << sum;
    return 0;
}