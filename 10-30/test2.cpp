//
// Created by hanzhi713 on 10/30/19.
//

#include <bits/stdc++.h>
using namespace std;
#define MAX 46341

//void SieveOfEratosthenes(int n)
//{
//    // Create a boolean array "prime[0..n]" and initialize
//    // all entries it as true. A value in prime[i] will
//    // finally be false if i is Not a prime, else true.
//    bool prime[n+1];
//    memset(prime, true, sizeof(prime));
//
//    for (int p=2; p*p<=n; p++)
//    {
//        // If prime[p] is not changed, then it is a prime
//        if (prime[p])
//        {
//            for (int i=p*p; i<=n; i += p)
//                prime[i] = false;
//        }
//    }
//}
//
int not_prime[46341] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    int T;
//    cin >> T;
    for (int x = 2; x * x < MAX; x++) {
        if (!not_prime[x]) {
            for (int i = x * x; i < MAX; i += x)
                not_prime[i] = 1;
        }
    }

    for (int x = 2; x < MAX; x++) {
        if (!not_prime[x]) {
            for (int i = 2 * x; i < MAX; i += x)
                not_prime[i] += 1;
        }
    }

    for (int j = 0; j < 10; ++j) {
        cout << not_prime[j] << endl;
    }
}