//
// Created by hanzhi713 on 10/9/19.
//

#include <bits/stdc++.h>
using namespace std;

char disk[5*100000];
int main() {
    memset(disk, 0, sizeof(disk));
    int n, c, b;
    cin >> n >> c >> b;
    for (int j = 0; j < b; ++j) {
        int idx;
        cin >> idx;
        disk[idx - 1] = -1;
    }

    int count = 0;
    int i = 0;
    if (c % 2 == 1) {
        disk[0] = 1;
        disk[1] = 0;
        count = 1;
        i = 2;
    } else {
        i = 1;
    }

    while (i < n && count < c) {
        if (disk[i] == -1) {
            disk[i++] = 0;
        } else {
            disk[i] = 1;
            disk[i + 1] = 0;
            count += 2;
            i += 2;
        }
    }
    while (i < n) {
        disk[i++] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << (int)(disk[i]);
    }
    cout << endl;
}