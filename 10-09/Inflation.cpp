#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int buffer[200007];

int main() {
	memset(buffer, 0, sizeof(buffer));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buffer[i];
	}

	sort(buffer, buffer + n);

	double result = 1;
	for (int i = 0; i < n; i++) {
		if (buffer[i] > i + 1) {
			cout << "impossible" << endl;
			break;
		} else if (result > buffer[i] * 1.0 / (i + 1)) {
			result = buffer[i] * 1.0 / (i + 1);
		}

		if (i == n - 1) {
			cout << result << endl;
		}
	}
}
