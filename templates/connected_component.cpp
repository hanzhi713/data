
int bfs(bool *visited, vector<int> *adjList, int *buffer, int size, int start) {
    int count = 0;
    queue<int> q;
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
