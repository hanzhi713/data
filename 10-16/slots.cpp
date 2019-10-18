#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x;
    double y;
};

double findDistance(Point &x1, Point &x2, Point &y1) {
    auto gradient = (x2.y - x1.y) / (x2.x - x1.x);
    auto c = gradient * x1.x - x1.y;
    return abs(-gradient * y1.x + y1.y + c) / sqrt(1 + gradient * gradient);
}

Point vertices[21];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> vertices[i].x >> vertices[i].y;
    }
    vertices[N] = vertices[0];
    double globalDist = 10e300;
    for (int i = 0; i < N; i++) {
        auto &x1 = vertices[i];
        auto &x2 = vertices[i + 1];
        double dist = 0.0;
        for (int j = 0; j < i; ++j) {
            auto cdist = findDistance(x1, x2, vertices[j]);
//            cout << i << " " << j << " " << cdist << endl;
            if (cdist > dist)
                dist = cdist;
        }
        for (int j = i + 2; j < N; ++j) {
            auto cdist = findDistance(x1, x2, vertices[j]);
            if (cdist > dist)
                dist = cdist;
        }
        if (dist != 0 && dist < globalDist) {
            globalDist = dist;
        }
    }

    cout << globalDist << endl;
}