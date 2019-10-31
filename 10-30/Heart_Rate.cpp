#include "stdcpp.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double b, p;
	cin >> n;
	while (n--) {
		cin >> b >> p;
		printf("%.4f %.4f %.4f\n", 60 * (b - 1) / p, 60 * b / p, 60 * (b + 1) / p);
	}

	return 0;
}
