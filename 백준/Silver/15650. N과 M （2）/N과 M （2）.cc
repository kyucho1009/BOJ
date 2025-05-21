#include <iostream>
#include <vector>
using namespace std;
vector <int> v;

int N , M;

void bt(int num) {
    if(v.size() == M) {
        for(int i = 0; i < M; i++) {
            cout << v[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i = num; i <= N; i++) {
        v.push_back(i);
        bt(i + 1); //한 층 더 깊이 들어간다
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    bt(1);
    return 0;
}