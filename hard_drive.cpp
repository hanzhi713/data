//
// Created by hanzhi713 on 10/9/19.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    const char CC = '0';
    int n, c, b;
    cin >> n >> c >> b;

    vector<int> broken;
    broken.push_back(1);
    for (int i = 0; i < b; ++i) {
        int temp;
        cin >> temp;
        broken.push_back(temp);
    }
    broken.push_back(n - 1);

    int count = 0;
    int x = 0;
    if (c % 2 == 1) {
        cout << '1';
        if (broken[1] == 2) count++;
    } else {
        cout << '0';
    }
    n--;

    for (int j = 1; j < broken.size(); ++j) {
        int total = broken[j] - broken[j - 1] - 1;
        bool flag = 1;
        for (int i = 0; i < total; ++i) {
            if (count >= c) goto end;
            cout << (char) (CC + flag);
            flag = !flag;
            count++;
            x++;
        }
        if (x == n) break;
        cout << '0';
        x++;
        count += total % 2 == 0 ? 0 : 1;
    }
    end:
    while (x < n) {
        x++;
        cout << '0';
    }
    cout << endl;
}