#include <bits/stdc++.h>
using namespace std;

int rec(int start, vector<int> *v, bool *visited) {
    int number = 0;
    for (auto neighbor : v[start]) {
        for (auto node : v[neighbor]) {
            if (!visited[node]) {
                visited[node] = true;
                number += rec(node, v, visited);
            }
        }
        if (!visited[neighbor]) {
            number++;
            visited[neighbor] = true;
            number += rec(neighbor, v, visited);
        }
    }
    return number;
}

int bfs(int start, bool *visited, vector<int> *adjList, int *buffer) {
    queue<int> q;
    buffer[0] = start;
    int count = 1;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        start = q.front();
        q.pop();
        for (auto i : adjList[start]) {
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
    int n, m;
    cin >> n >> m;
    auto v = new vector<int>[n]();
    for (int i = 0; i < m; i++) {
        int t, s;
        cin >> t >> s;
        t--;
        s--;
        v[t].push_back(s);
        v[s].push_back(t);
    }
    bool *hasComp = new bool[n]();
    bool *visited = new bool[n]();
    int *comp = new int[n]();
    int count = 0;
    int globalMin = INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (!hasComp[i]) {
            int num_nodes = bfs(i, hasComp, v, comp);
            int min = rec(comp[0], v, visited) != 0;
            if (min < globalMin && num_nodes > 1)
                globalMin = min;
            count++;
        }
    }
    cout << count - 1 + globalMin << endl;
}