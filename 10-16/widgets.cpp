//
// Created by hanzhi713 on 10/17/19.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    const ll sqN = ceil(sqrt(N));
    const ll low1 = max(floor(sqN / sqrt(2.0)), 1.0);
    ll diff = sqN * sqN - N;
    if (diff == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (ll i = low1; i < sqN; ++i) {
        ll newDiff = i - N % i;
        newDiff = newDiff == i ? 0 : newDiff;
        ll another =  N / i + (newDiff != 0);
        if (another <= i * 2 && newDiff < diff) {
            diff = newDiff;
        }
    }
    cout << diff << endl;
    return 0;
}
