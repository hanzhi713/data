/**
 * To compile and run:
 * clang++ -o p p.cpp && ./p
 */
#include <iostream>
#include <string>
#include<cstring>
#include <vector>

using namespace std;

vector<int8_t>* v;
int graph[26][26];
int n, m;

bool hc(int start, bool *visited, int num) {
    if (num == n) {
        return true;
    }
    auto &nv = v[start];
    for (auto node : nv) {
        if (!visited[node]) {
            visited[node] = true;
            if (hc(node, visited, num + 1)) {
                return true;
            } else {
                visited[node] = false;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    memset(graph, 0, n * n * 4);
    for (int i = 0; i < m; i++) {
        int votes;
        cin >> votes;
        string candidates;
        cin >> candidates;
        for (int j = 0; j < n; j++) {
            int a = candidates[j] - 65;
            for (int k = j + 1; k < n; k++) {
                int b = candidates[k] - 65;
                graph[a][b] += votes;
            }
        }
    }

    v = new vector<int8_t>[n]();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] > graph[j][i]) {
                v[i].push_back(j);
            } else {
                v[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        auto& vec = v[i];
        for (auto j : vec) {
            cout << (int) j << " ";
        }
        cout << endl;
    }

    // int* cache = new int[n];
    // memset(cache, -1, n * 4);
    // for(int i = 0; i < n; i ++){
    bool *visited = new bool[n]();
    visited[0] = true;
    bool b = hc(0, visited, 0);
    cout << (char) (65 + 0) << ": " << (b == 0 ? "can't win" : "can win") << endl;
    // }

    return 0;
}