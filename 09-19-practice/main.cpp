//
// Created by hanzhi713 on 9/18/19.
//

#include <bits/stdc++.h>

using namespace std;

queue<int16_t> q;

int16_t bfs(bool *visited, vector<int16_t> *adjList, int16_t *buffer, int16_t size, int16_t start) {
    int16_t count = 0;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        start = q.front();
        q.pop();
        auto& neighbors = adjList[start];
        for (auto i : neighbors) {
            if (!visited[i]) {
                visited[i] = true;
                buffer[count++] = i;
                q.push(i);
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int16_t size;
    cin >> size;
    bool *matrix = new bool[size * size]();
    bool *connectivity = new bool[size * size]();
    auto *adjList = new vector<int16_t>[size]();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int a;
            cin >> a;
            matrix[i * size + j] = a;
            if (a) adjList[i].push_back(j);
        }
    }
    bool *visited = new bool[size]();
    auto *buffer = new int16_t[size - 1]();
    for (int16_t i = 0; i < size; i++) {
        int16_t count = bfs(visited, adjList, buffer, size, i);
        for (int16_t j = 0; j < count; j++) {
            connectivity[i * size + buffer[j]] = true;
        }
        memset(buffer, 0, (size - 1) * 2);
        memset(visited, 0, size);
    }
    int count = 0;
    for (int i = 0; i < size * size; i++) {
        count += connectivity[i] - matrix[i];
    }
    cout << count << endl;
    return 0;
}