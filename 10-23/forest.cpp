//
// Created by hanzhi713 on 10/23/19.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
#define int long long

    int a, b;
    cin >> a >> b;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int c = __gcd(a, b);
    int A = a / c;
    int B = b / c;

    int p1x = A, p1y = B;
    int p2x = a - A, p2y = b - B;

    
}