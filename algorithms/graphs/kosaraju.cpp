#include "bits/stdc++.h"
using namespace std;

int nodes, edges;
vector<int> roots;
vector<bool> visited;
vector<int> root_nodes;
vector<vector<int> > scc;
vector<vector<int> > adj;
vector<vector<int> > adj_rev;
vector<int> order, component;

void dfs1(int v) {
    visited[v] = true;

    for(auto u : adj[v])
        if(!visited[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    component.push_back(v);

    for(auto u : adj_rev[v])
        if(!visited[u])
            dfs2(u);
}

bool check(){
    bool ans = true;
    for(int i = 0; i < nodes; i++){
        if(visited[i] == false){
            ans = false;
        }
        visited[i] = false;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> nodes >> edges;

    adj.resize(nodes);
    visited.resize(nodes);
    adj_rev.resize(nodes);

    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjListReverse[v].push_back(u);
    }

    visited.assign(nodes, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }

    visited.assign(nodes, false);
    reverse(order.begin(), order.end());
    
    roots.assign(nodes, 0);

    for(auto v : order){
        if(!visited[v]) {
            dfs2 (v);
            
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            
            component.clear();
        }
    }
    
    for (int v = 0; v < nodes; v++){
        for (auto u : adj[v]) {
            int root_v = roots[v], root_u = roots[u];

            if (root_u != root_v)
                scc[root_v].push_back(root_u);
        }
    }

    return 0;
}
