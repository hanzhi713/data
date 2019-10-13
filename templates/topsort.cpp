/**
 * To compile and run:
 * clang++ -o topsort topsort.cpp && ./topsort
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @param graph is the adjacency list, graph[a] contains b if a is pre-req of b
 * @param degrees is the in-degree of nodes in graph, e.g. 0 if no pre-req
 *
 * @returns topological order of the graph
 */
vector<int> topsort(vector<vector<int>>& graph, int* degrees){
    int counter = 0;
    queue<int> q;
    vector<int> result;

    for(int i = 0; i < graph.size(); i++){
        if(degrees[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int idx = q.top();
        q.pop();
        result.push_back(idx);
        for(int i = 0; i < graph[idx].size(); i++){
            degrees[graph[idx][i]] -= 1;
            if(degrees[graph[idx][i]] == 0){
                q.push(graph[idx][i]);
            }
        }
        counter++;
    }
}

int main(){

}