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

//typedef pair<int, double> pid;
//double prim(vector<pid>* adjList, int n) {
//    int start = 0;
//    auto comp = [](auto &a, auto &b) { return a.second > b.second; };
//    priority_queue<pid, vector<pid>, decltype(comp)> q(comp);
//
//    q.push({start, 0});
//    auto *visited = new bool[n]();
//    auto* keys = new double[n]();
//
//    keys[0] = 0;
//    while (!q.empty()) {
//        start = q.top().first;
//        q.pop();
//        visited[start] = true;
//        for (auto &p: adjList[start]) {
//            int i = p.first;
//            auto weight = p.second;
//            if (!visited[i] && weight < keys[i] ) {
//                keys[i] = weight;
//                q.push({i, weight});
//            }
//        }
//    }
//
////    delete[] visited;
//    return accumulate(keys, keys + n, 0.0);
//}


struct Temp {
    int val;
    double cost;
};

double prim(const double *matrix, int n) {
    int start = 0;
    auto comp = [](Temp &a, Temp &b) { return a.cost > b.cost; };
    priority_queue<Temp, vector<Temp>, decltype(comp)> q(comp);

    auto *visited = new bool[n]();
    auto *keys = new double[n]();

    keys[0] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        start = q.top().val;
        q.pop();
        visited[start] = true;
        for (int i = 0; i < n; i++) {
            double weight = matrix[start * n + i];
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
//    auto *adjList = new vector<pair<int, double>>[N]();
    auto *matrix = new double[N * N]();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            auto &d1 = dishes[i];
            auto &d2 = dishes[j];
            int dx = d1.x - d2.x;
            int dy = d1.y - d2.y;
            int dsq = dx * dx + dy * dy; // distance squared
            int r = d1.r + d2.r;
            if (dsq == r * r) {
//                adjList[i].push_back({j, 0});
//                adjList[j].push_back({i, 0});
                matrix[i * N + j] = matrix[j * N + i] = 0;
            } else {

                auto dd = sqrt(dsq) - r;
                matrix[i * N + j] = matrix[j * N + i] = dd;
//                adjList[i].push_back({j, dd});
//                adjList[j].push_back({i, dd});
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i * N + j] << " ";
        }
        cout << endl;
    }
    cout << prim(matrix, N) << endl;
}
