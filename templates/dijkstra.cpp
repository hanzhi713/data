/**
 * To compile and run:
 * clang++ -o dijkstra dijkstra.cpp && ./dijkstra
 */
#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<int>>& graph, int s){
    int* distance = new int[graph.size()];
    bool* known = new bool[graph.size()];
    memset(distance, 0x7f, graph.size() * 4); // actually to intmax lol
    memset(known, 0, graph.size());

    distance[s] = 0;
    int v, w;
    v = s;

    auto comp = [&](int a, int b){
        return distance[a] < distance[b];
    };

    priority_queue<int, vector<int>, decltype(comp)> q(comp);

    for(int i = 0; i < graph.size(); i++){
        q.push(i);
    }

    while(!q.empty()){
        v = q.top();
        q.pop();
        known[v] = true;

        for(int i = 0; i < graph[v].size(); i++){
            if(graph[v][i] == 0) continue;
            w = i;
            if(!known[w]){
                if(distance[v] + graph[v][w] < distance[w]){
                    distance[w] = distance[v] + graph[v][w];
                }
            }
        }
    }
}

int main(){
    
    return 0;
}