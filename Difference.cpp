#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool buffer[1023000017];
std::vector<int> v;

int main() {
	memset(buffer, sizeof(buffer), 0);
	int a, m, step = 1, d;
	cin >> a >> m;
	buffer[a] = 1;
	d = a == 1 ? 2 : 1;

	while (buffer[m] == 0) {
		step++;
		a += d;
		buffer[a] = 1;
		v.push_back(d);
		buffer[d] = 1;

		int temp = d;
		for (int i = v.size() - 2; i > -1; i--) {
			temp += v[i];
			buffer[temp] = 1;
		}

		while (buffer[d] == 1) {
			d++;
		}
	}

	cout << step << endl;
}
