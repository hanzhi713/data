#include "stdcpp.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h, v;
	cin >> n >> h >> v;
	printf("%d\n", max(h, n - h) * max(v, n - v) * 4);

	return 0;
}
