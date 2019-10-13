//
// Created by hanzhi713 on 10/13/19.
//

#include <bits/stdc++.h>

using namespace std;

bool buffer[2000007];
char num[2000007];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(buffer, 0, sizeof(buffer));
    for (int i = 2; i < 1000007; i++) {
        int j = 2;
        while (i * j < 2000007) {
            buffer[i * j] = 1;
            j++;
        }
    }

    for (int i = 2; i < 2000007; i++) {
        if (buffer[i] == 0) {
            continue;
        }

        int j = 1;
        while (i * j < 2000007) {
            num[i * j] += 1;
            j++;
        }
    }

    int q, i;
    cin >> q;
    while (q--) {
        cin >> i;
        cout << num[i] + 1 << endl;
    }
}
