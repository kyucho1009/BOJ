#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    queue<int> q;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        
        if(s == "push") {
            int num;
            cin >> num;
            q.push(num);
        }

        else if(s == "pop") {
            if(q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        else if(s == "size") {
            cout << q.size() << "\n";
        }

        else if(s == "empty") {
            cout << q.empty() << "\n";
        }

        else if(s == "front") {
            if(q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }

        else if(s == "back") {
            if(q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
}