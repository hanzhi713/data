//
// Created by hanzhi713 on 9/25/19.
//

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

struct Temp {
    int val;
    double cost;
};

double prim(double *matrix, double* keys, int n) {
    int start = 0;
    auto comp = [](Temp &a, Temp &b) { return a.cost > b.cost; };
    priority_queue<Temp, vector<Temp>, decltype(comp)> q(comp);

    q.push({start, 0});
    auto *visited = new bool[n]();
    keys[0] = 0;
    while (!q.empty()) {
        start = q.top().val;
        q.pop();
        visited[start] = true;
        for (int i = 0; i < n; i++) {
            double weight = matrix[start * n + i];
            if (!visited[i] && weight < keys[i] ) {
                keys[i] = weight;
                q.push({i, weight});
            }
        }
    }
    return accumulate(keys, keys + n, 0.0);
}


int main() {
    int p, e, n;
    cin >> n >> e >> p;
    auto *matrix = new double[n * n]();
    auto *points = new Point[n];

    for (int i = 0; i < e; i++) {
        cin >> points[i].x >> points[i].y;
    }
    for (int i = 0; i < e; i++) {
        for (int j = i + 1; j < e; j++) {
            matrix[j * n + i] = matrix[i * n + j] = -1;
        }
    }

    for (int i = e; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // max(e, j + 1)
            if (matrix[j * n + i] != -1) {
                auto x1 = points[i].x;
                auto y1 = points[i].y;
                auto diffx = points[j].x - x1;
                auto diffy = points[j].y - y1;
                matrix[j * n + i] = matrix[i * n + j] = sqrt(diffx * diffx + diffy * diffy);
            } else {
                matrix[j * n + i] = matrix[i * n + j] = 0;
            }
        }
    }

    for (int asd = 0; asd < p; asd++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        matrix[a * n + b] = matrix[b * n + a] = 0;
    }

    auto* keys = new double[n];
    for (int i = 0; i < n; i++) {
        keys[i] = 10e300;
    }

    cout << prim(matrix, keys, n) << endl;
}