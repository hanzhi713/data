#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 20;
double graph[SIZE][SIZE];
double *dijkstra(int n, int v) {
    auto *distance = new double[n];
    distance[v] = 0;
    for (int j = 1; j < n; ++j)
        distance[j] = 10e300; //numeric_limits<double>::max();

    auto comp = [=](int a, int b) {
        return distance[a] > distance[b];
    };
    priority_queue<int, vector<int>, decltype(comp)> q(comp);
    q.push(v);
    while (!q.empty()) {
        v = q.top();
        q.pop();
        for (int i = 0; i < n; i++) {
            auto weight = graph[v][i];
            if (weight == 0) continue;
            if (distance[v] + weight < distance[i]) {
                distance[i] = distance[v] + weight;
                q.push(i);
            }
        }
    }
    return distance;
}

int main() {
    auto *dist = dijkstra(SIZE, 0);
    for (int i = 0; i < SIZE; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}