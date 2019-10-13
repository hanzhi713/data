//
// Created by hanzhi713 on 10/13/19.
//

#include <iostream>
#include <string.h>
using namespace std;
int buffer[407];

int main() {
    memset(buffer, 0, sizeof(buffer));
    int n, si, ti;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> si >> ti;

        for (int j = si; j <= ti; j++) {
            buffer[j] = 1;
        }
    }

    int count = 0;
    for (int i = 1; i <= 365; i++) {
        if (buffer[i] == 1) {
            count++;
        }
    }

    cout << count << endl;
}
