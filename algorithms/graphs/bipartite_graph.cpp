#include "bits/stdc++.h"
using namespace std;

vector<bool> visit;
vector<bool> color;
vector<vector<int> > adj;

bool isBipartite(int v){ 
    for (int u : adj[v]) { 
        if (visit[u] == false) { 
            visit[u] = true; 
            color[u] = !color[v]; 
  
            if (!isBipartite(u)) return false; 
        } 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 

int main(){
    int n, e;

    while(cin >> n >> e){
        
        adj.resize(n);
        visit.resize(n);
        color.resize(n);

        for(int i = 0; i < e; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visit[0] = true;
        color[0] = false;

        if(isBipartite(0)){
            cout << "BICOLORABLE.\n";
        }
        else cout << "NOT BICOLORABLE.\n";

        adj.clear();
        visit.clear();
        color.clear();
    }

    return 0;
}
