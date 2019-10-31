//
// Created by hanzhi713 on 10/30/19.
//

#include <bits/stdc++.h>
using namespace std;
#define MAX 46341
bool prime[MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(prime, true, sizeof(prime));

    for (int x = 2; x * x < MAX; x++) {
        if (prime[x]) {
            for (int i = x * x; i < MAX; i += x)
                prime[i] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i < MAX; ++i) {
        if (prime[i])
            primes.push_back(i);
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int start;
        string name;
        cin >> start >> name;
        unordered_map<int, int> factors;
        for (auto j: primes) {
            while (start % j == 0) {
                start /= j;
                factors[j]++;
            }
            if (start == 1) goto end;
        }
        factors[start] = 1;
        end:;
        if (factors.size() >= 3) {
            cout << "tie" << '\n';
        } else if (factors.size() == 1) {
            auto it = factors.begin();
            if (it->second % 2 == 0) {
                cout << (name == "Alice" ? "Bob" : "Alice") << '\n';
            } else {
                cout << name << '\n';
            }
        } else {
            auto it = factors.begin();
            int diff = abs(it->second - (++it)->second);
            if (diff >= 2) {
                cout << "tie" << '\n';
            } else if (diff == 1) {
                cout << name << '\n';
            } else {
                cout << (name == "Alice" ? "Bob" : "Alice") << '\n';
            }
        }
    }
}