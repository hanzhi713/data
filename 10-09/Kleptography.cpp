#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int n, m;
	string last, cipher;
	cin >> n >> m >> last >> cipher;

	int index = m - 1;
	while (last.length() < m) {
		char k = (cipher[index--] - 'a') - (last[n - 1] - 'a');
		if (k < 0) {
			k += 26;
		}
		last = (char) (k + 'a') + last;
	}

	cout << last << endl;
}
