//
// Created by hanzhi713 on 10/13/19.
//


#include <bits/stdc++.h>
using namespace std;

long long H(long long previousHash, string &transaction) {
    long long v = previousHash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007LL;
    }
    return v * 7;
}

long long Hash(long long previousHash, string &transaction, long long token) {
    long long v = previousHash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007LL;
    }
    return (v * 7 + token) % 1000000007LL;
}

long long findToken(long long v) {
    v %= 1000000007LL;
//    cout << v << endl;
    if (v > 1000000000LL) {
        return 2000000000LL - v;
    } else {
        return 10000000 - v % 10000000LL;
    }
}

int main() {
    long long prevHash;
    cin >> prevHash;

    string a1 = "team-2cats1vulture";
    string a2 = "team-2vultures1cat";

    long long H1 = H(prevHash, a1);
    long long token1 = findToken(H1);

    cout << a1 << " " << token1 << endl;
//    cout << Hash(prevHash, a1, token1) << endl;

    long long H2 = H((token1 + H1) % 1000000007LL, a2);
    long long token2 = findToken(H2);

//    cout << Hash((token1 + H1) % 1000000007LL, a2, token2) << endl;
    cout << a2 << " " << token2 << endl;

}