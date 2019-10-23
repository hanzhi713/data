#include "stdcpp.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double i, j, result = 0;
	cin >> n;
	while (n--) {
		cin >> i >> j;
		result += i * j;
	}

	printf("%f\n", result);

	return 0;
}
