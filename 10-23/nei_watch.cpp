#include <bits/stdc++.h>

using namespace std;
int main() {
#define int long long
    int N, K;
    cin >> N >> K;
    int count = 0;
    int last_safe = 0;
    int safe = 0;
    for (int i = 0; i < K; ++i) {
        cin >> safe;
        int n = safe - last_safe - 1;
        count += n * (n + 1) / 2;
        last_safe = safe;
    }
    int n = N - safe;
    count += n * (n + 1) / 2;
    cout << N * (N + 1) / 2 - count << endl;
}

