//
// Created by hanzhi713 on 11/6/2019.
//

#include <bits/stdc++.h>
using namespace std;

struct line {
    double k;
    double b;
};

line lines[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double gradient = (y2 - y1) / static_cast<double>(x2 - x1);

    }
}