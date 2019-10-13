#include <bits/stdc++.h>
using namespace std;

int rec(int start, vector<int> *v, bool *visited) {
    int number = 0;
    for (int i = 0; i < v[start].size(); i++) {
        int neighbor = v[start][i];

        for (int j = 0; j < v[neighbor].size(); j++) {
            if (!visited[v[neighbor][j]]) {
                visited[v[neighbor][j]] = true;
                number += rec(v[neighbor][j], v, visited);
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

void dfs(int start, vector<int> *v, bool *visited, vector<int> &component) {
    visited[start] = true;
    component.push_back(start);
    for (int i = 0; i < v[start].size(); i++) {
        if (!visited[v[start][i]]) {
            visited[v[start][i]] = true;
            dfs(v[start][i], v, visited, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    auto v = new vector<int>[n]();
    for (int i = 0; i < m; i++) {
        int t, s;
        cin >> t >> s;
        v[t - 1].push_back(s - 1);
        v[s - 1].push_back(t - 1);
    }

    bool *hasComp = new bool[n]();
    int count = 0;
    int globalMin = INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (!hasComp[i]) {
            vector<int> temp;
            dfs(i, v, hasComp, temp);
            count++;

            int min = INT32_MAX;
            bool *visited = new bool[n]();
            int v123 = rec(temp[0], v, visited);
            min = v123 == 0 ? 0 : 1;

            if (min < globalMin && temp.size() > 1)
                globalMin = min;
            delete[] visited;
        }
    }

    cout << count - 1 + globalMin << endl;
}