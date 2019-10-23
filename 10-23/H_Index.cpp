#include "stdcpp.h"
using namespace std;

int buffer[100007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(buffer, 0, sizeof(buffer));
	int n, c, min = 1000000007;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buffer[i];
	}

	sort(buffer, buffer + n);
	int result = 0;
	for (int i = n - 1; i > -1; i--) {
		if (buffer[i] > result) {
			result++;
		}
	}

	printf("%d\n", result);

	return 0;
}
