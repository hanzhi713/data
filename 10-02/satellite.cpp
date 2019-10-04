//
// Created by hanzhi713 on 10/3/19.
//

#include <bits/stdc++.h>
using namespace std;

struct Dish {
    int x;
    int y;
    int r;
};

Dish dishes[2000];
double graph[2000][2000];

struct Temp {
    int val;
    double cost;
};

double prim(int n) {
    int start = 0;
    auto comp = [](Temp &a, Temp &b) { return a.cost > b.cost; };
    priority_queue<Temp, vector<Temp>, decltype(comp)> q(comp);

    auto *visited = new bool[n]();
    auto *keys = new double[n]();
    keys[0] = 0;
    for (int i = 1; i < n; i++) {
        keys[i] = 10e300;
    }

    q.push({start, 0});

    while (!q.empty()) {
        start = q.top().val;
        q.pop();
        visited[start] = true;
        for (int i = 0; i < n; i++) {
            double weight = graph[start][i];
            if (!visited[i] && weight < keys[i]) {
                keys[i] = weight;
                q.push({i, weight});
            }
        }
    }
    return accumulate(keys, keys + n, 0.0);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> dishes[i].x >> dishes[i].y >> dishes[i].r;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dx = dishes[i].x - dishes[j].x;
            int dy = dishes[i].y - dishes[j].y;
            int r = dishes[i].r + dishes[j].r;
            int dsq = dx * dx + dy * dy; // distance squared
            if (dsq == r * r) {
                graph[i][j] = graph[j][i] = 0;
            } else {
                graph[i][j] = graph[j][i] = sqrt(dsq) - r;
            }
        }
    }
    cout.precision(numeric_limits<double>::max_digits10);
    cout << prim(N) << endl;
}
