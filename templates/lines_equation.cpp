#include <bits/stdc++.h>
using namespace std;

/**
 * parametric line equation
 * <x, y> = s * <v1, v2> + <b1, b2>
 */
struct Line {
    double v1;
    double v2;
    double b1;
    double b2;
};

struct Point {
    double x;
    double y;
};

Line lines[100];

Point intercept(const Line &l1, const Line &l2) {
    double temp = l2.v1 * l1.v2 - l2.v2 * l1.v1;
    if (abs(temp) < 1e-7)
        return {10e300, 10e300};
    double w1 = l1.b1 - l2.b1;
    double w2 = l1.b2 - l2.b2;
    double s = (l2.v2 * w1 - l2.v1 * w2) / temp;
    return {l1.v1 * s + l1.b1, l1.v2 * s + l1.b2};
}

double dist(const Point &p1, const Point &p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double dx = x2 - x1;
        double dy = y2 - y1;
        lines[i].v1 = dx;
        lines[i].v2 = dy;
        lines[i].b1 = x1;
        lines[i].b2 = y1;
    }
}