//
// Created by hanzhi713 on 10/13/19.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, B;
    cin >> N >> M >> B;

    unordered_map<int, unordered_map<int, bool>> graph;
    int start_r, start_c;
    cin >> start_r >> start_c;
    for (int i = 1; i < B; ++i) {
        int r, c;
        cin >> r >> c;
        graph[r][c] = true;
    }

    for (int j = 0; j < B; ++j) {

    }
}