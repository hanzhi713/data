/**
 * To compile and run:
 * clang++ -o bfs bfs.cpp && ./bfs
 */
#include <bits/stdc++.h>
using namespace std;

int n;

/**
 * Unweighted shortest path with BFS
 * @param graph: adjacency list, directed or undirected
 * @param s: starting edge
 * 
 * distance: min distance of nodes to s
 * path: last node to s
 */
void bfs(vector<int>* graph, int s){
    queue<int> q;
    int v, w;
    q.push(s);
    
    int* distance = new int[n];
    int* path = new int[n];
    memset(distance, -1, n * sizeof(int));
    memset(path, -1, n * sizeof(int));

    distance[s] = 0;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i < graph[v].size(); i++){
            w = graph[v][i];
            if(distance[w] == -1){
                distance[w] = distance[v] + 1;
                path[w] = v;
                q.push(w);
                cout<<"("<<v<<", "<<w<<")"<<endl;
            }
        }
    }
}

int main(){
    cin>>n;
    auto graph = new vector<int>[n]();
    for(int i = 0; i < n; i ++){
        int t;
        cin>>t;
        for(int j = 0; j < t; j++){
            int s;
            cin>>s;
            graph[i].push_back(s);
        }
    }

    bfs(graph, 0);

    return 0;
}