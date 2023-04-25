#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num;
	cin >> num;
	queue<int> q;
	for(int i = 1; i <= num; i++) {
		q.push(i);
	}
	while(q.size() != 1) {
		q.pop();
		if(q.size() == 1) {
			break;
		}
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}