#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define tmax 10015

struct grafo{
    vector<pair<int,int>>edge[tmax];
    bool mark[tmax];
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    int numvert, nfi, ind;
    int dist[tmax];
    pair<int,int>tmp;
    void add_edge(int u, int v, int peso){
        edge[u].push_back(make_pair(peso,v));
    }

    void dijkstra(int ori, int dest){
        memset(mark,false,sizeof(bool)*(numvert +1));

        for(ind = 0; ind <= numvert; ind++){
            dist[ind] = INT_MAX;
        }
        dist[ori] = 0;
        min_heap.push(make_pair(0, ori));
        while(!min_heap.empty()){
            tmp = min_heap.top();
            min_heap.pop();

            if(!mark[tmp.second]){
                mark[tmp.second] = true;

                nfi = edge[tmp.second].size();
                for(ind = 0; ind < nfi; ind++){
                    if(dist[edge[tmp.second][ind].second] > dist[tmp.second] + edge[tmp.second][ind].first){
                        dist[edge[tmp.second][ind].second] = dist[tmp.second] + edge[tmp.second][ind].first;
                        min_heap.push(make_pair(dist[edge[tmp.second][ind].second], edge[tmp.second][ind].second));
                    }
                }
            }
        }
    }

    void mostra(int ori){
        for(ind = 1; ind <= numvert; ind++){
            printf(" da origem %d ate %d, min dist %d\n", ori,ind, dist[ind]);
        }
    }

    void distancia(int v){
        if(dist[v] != INT_MAX){
            printf("%d\n", dist[v]);
        }else{
            printf("NO\n");
        }
    }
};


int main(){
    int vezes, m, n, u, v, peso, ind;
    scanf("%d", &vezes);
    while(vezes--){
        grafo g;
        scanf("%d %d", &m,&n);
        g.numvert = m;
        for(ind = 0; ind < n; ind++){
            scanf("%d %d %d", &u,&v,&peso);
            g.add_edge(u,v,peso);
        }
        scanf("%d %d", &u,&v);
        g.dijkstra(u, v);
        g.distancia(v);
    }
    return 0;
}
