#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 2000001;
uint16_t not_prime[MAX] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int x = 2; x * x < MAX; x++) {
        if (!not_prime[x]) {
            for (int i = x * x; i < MAX; i += x)
                not_prime[i] = 1;
        }
    }
    for (int x = 2; x < MAX; x++) {
        if (not_prime[x]) {
            for (int i = x; i < MAX; i += x)
                not_prime[i] += 1;
        }
    }
    for (int j = 2; j < MAX; ++j) {
        not_prime[j] += not_prime[j] == 0;
    }

    int q, i;
    cin >> q;
    for (int _ = 0; _ < q; ++_) {
        cin >> i;
        cout << not_prime[i] << '\n';
    }
    return 0;
}