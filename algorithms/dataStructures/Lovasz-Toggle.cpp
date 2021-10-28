#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define Grafo vector<vector<int>>

using namespace std;

Grafo grafo;
int color[300000];
unordered_set <int> bad;

void getBad(int u, int maxEnemyNumber) {
    if(grafo[u].size() > maxEnemyNumber) bad.insert(u);
    color[u] = 0;
    for(auto v : grafo[u]) {
        if(color[v] == -1) {
            color[v] = 0;
            getBad(v, maxEnemyNumber);
        }
    }
}

void lovaszToggle(int vertex, int maxEnemyNumber) { // the vertex you begin and the maximum enemies number
    bad.clear();
    getBad(vertex, maxEnemyNumber);
    while(!bad.empty()) {
        int u = *(bad.begin()); // first element of bad  
        color[u] = !color[u]; // change color
        bad.erase(bad.begin()); // erase this element from bad
        for(auto v : grafo[u]) { // update the neighbors
            int enemyNumber = 0;
            for(auto val : grafo[v]) {
                if(color[v] == color[val]) {
                    enemyNumber++;
                }    
            }
            if(enemyNumber > maxEnemyNumber && !bad.count(v)) {
                bad.insert(v);
            } else if(enemyNumber <= maxEnemyNumber && bad.count(v)) {
                bad.erase((bad.find(v)));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin >> n >> m;
    grafo.resize(n + 1);
    for(int i = 1; i <= n; i++) color[i] = -1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            lovaszToggle(i, 2);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(color[i] == 1) cout << 'A';
        else cout << 'B';
    }
    cout << endl;
}
