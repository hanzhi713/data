//
// Created by ky on 10/12/19.
//
#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 2000;
double graph[SIZE][SIZE];
double prim(int n) {
    int start = 0;
    auto comp = [](auto &a, auto &b) { return a.second > b.second; };
    priority_queue<pair<int, double>, pair<int, double>, decltype(comp)> q(comp);

    auto *visited = new bool[n]();
    auto *keys = new double[n]();
    keys[0] = 0;
    for (int i = 1; i < n; i++) {
        keys[i] = 10e300;
    }
    q.push({start, 0});
    while (!q.empty()) {
        start = q.top().first;
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

    delete[] visited;
    delete[] keys;
    return accumulate(keys, keys + n, 0.0);
}