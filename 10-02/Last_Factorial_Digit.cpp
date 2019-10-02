#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 1) {
		return n;
	}

	return n * factorial(n - 1);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << *(to_string(factorial(n)).end() - 1) << endl;
	}
}