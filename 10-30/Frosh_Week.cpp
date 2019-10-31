#include "stdcpp.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, t;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int> > task;
	priority_queue<int, vector<int>, greater<int> > interval;

	for (int i = 0; i < n; i++) {
		cin >> t;
		task.push(t);
	}

	for (int i = 0; i < m; i++) {
		cin >> t;
		interval.push(t);
	}

	int count = 0;
	while (task.size() > 0 && interval.size() > 0) {
		if (task.top() <= interval.top()) {
			count++;
			task.pop();
			interval.pop();
		} else {
			interval.pop();
		}
	}

	printf("%d\n", count);

	return 0;
}
