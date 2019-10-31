//
// Created by ky on 10/30/19.
//
#include <bits/stdc++.h>
using namespace std;

#define MAX 123456
bool prime[MAX];
int main() {
    memset(prime, true, sizeof(prime));
    for (int x = 2; x * x < MAX; x++) {
        if (prime[x]) {
            for (int i = x * x; i < MAX; i += x)
                prime[i] = false;
        }
    }
}