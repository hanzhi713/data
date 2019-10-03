//
// Created by hanzhi713 on 9/21/19.
//


#include <bits/stdc++.h>

using namespace std;
int points[16];
struct Point {
    int x;
    int y;
};
Point buffer[8];

double tsp(double* graph, int numPoint) {
    for (int i = 0; i < numPoint; i++) {
        points[i] = i;
    }

    double minDist = 10e300;
    do {
        double dist = graph[numPoint * points[0] + points[numPoint - 1]];
//        double dist = 0;
        for (int i = 1; i < numPoint; i++) {
            dist += graph[numPoint * points[i - 1] + points[i]];
        }
        if (dist < minDist) {
            minDist = dist;
        }
    } while (next_permutation(points, points + numPoint));
    return minDist;
}

int main() {
    int numTowns;
    cin >> numTowns;
    double beforeCost = 0;

    int *numPoints = new int[numTowns];
    double graph[8 * 8];
    for (int i = 0; i < numTowns; i++) {
        int numPoint;
        cin >> numPoint;

        numPoints[i] = numPoint;
        for (int j = 0; j < numPoint; j++) {
            cin >> buffer[j].x >> buffer[j].y;
        }
        for (int j = 0; j < numPoint; j++) {
            for (int k = j + 1; k < numPoint; k++) {
                int x1 = buffer[j].x;
                int y1 = buffer[j].y;
                int dx = x1 - buffer[k].x;
                int dy = y1 - buffer[k].y;
                graph[j * numPoint + k] = graph[k * numPoint + j] = sqrt(
                        static_cast<double>(dx * dx) + static_cast<double>(dy * dy));
            }
        }
        beforeCost += tsp(graph, numPoint);
    }
    int merged[16 * 16];
    for (int i = 0; i < numTowns; i++) {
        for (int j = i + 1; j < numTowns; j++) {

        }
    }
    cout.precision(numeric_limits<double>::max_digits10);
    cout << beforeCost << endl;
}