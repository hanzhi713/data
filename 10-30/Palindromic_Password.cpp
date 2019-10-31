#include "stdcpp.h"
using namespace std;

bool isPalindrome(string s) {
	if (s.length() == 0 || s.length() == 1) {
		return true;
	}

	return s[0] == s[s.length() - 1] && isPalindrome(s.substr(1, s.length() - 2));
}

int buffer[1000007];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(buffer, 0, sizeof(buffer));
	for (int i = 100000; i < 1000000; i++) {
		if (isPalindrome(to_string(i))) {
			buffer[i] = i;
			v.push_back(i);
		}
	}

	int index = -1;
	for (int i = 100000; i < 1000000; i++) {
		if (buffer[i] == i) {
			index++;
			continue;
		} else if (i <= *v.begin()) {
			buffer[i] = *v.begin();
		} else if (i >= *(v.end() - 1)) {
			buffer[i] = *(v.end() - 1);
		} else if (i - v[index] <= v[index + 1] - i) {
			buffer[i] = v[index];
		} else {
			buffer[i] = v[index + 1];
		}
	}

	int n, i;
	cin >> n;
	while (n--) {
		cin >> i;
		printf("%d\n", buffer[i]);
	}

	return 0;
}
