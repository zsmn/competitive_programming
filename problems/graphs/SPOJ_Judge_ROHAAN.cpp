#include <stdio.h>
#include <limits.h>
using namespace std;
#define dir true
#define n_dir false
class grafo{
    private:
        struct head_graph{
            int **matriz_ad;
            int numvert;
            int numares;
            bool direct;
        };
        bool criado = false;
        head_graph g;
    public:
        void create_graph(int tmax, bool tipo){
            g.matriz_ad = new int*[tmax];
            for(int i = 0; i < tmax; i++){
                g.matriz_ad[i] = new int[tmax];
            }
            g.numares = 0;
            g.numvert = tmax;
            g.direct = tipo;
            criado = true;
            for(int i = 0; i <tmax; i++){
                for(int j = 0; j<tmax; j++){
                    if(i != j){
                        g.matriz_ad[i][j] = INT_MAX;
                    }
                    else{
                        g.matriz_ad[i][j] = 0;
                    }
                }
            }
        }
        void floyd_warshall(){
            for(int k = 0; k < g.numvert; k++){
                for(int i = 0; i < g.numvert; i++){
                    for(int j = 0; j <g.numvert; j++){
                        if((g.matriz_ad[i][k]!= INT_MAX)
                                &&(g.matriz_ad[k][j] != INT_MAX)
                                    &&(g.matriz_ad[i][j] > g.matriz_ad[i][k] +g.matriz_ad[k][j])){
                            g.matriz_ad[i][j] = g.matriz_ad[i][k] +g.matriz_ad[k][j];
                        }
                    }
                }
            }
        }
        void add_edge(int u, int v, int peso){
            if(criado){
                g.numares++;
                g.matriz_ad[u][v] = peso;
                if(!g.direct){
                    g.matriz_ad[v][u] = peso;
                }
            }
        }
        int custo(int i, int j){
            return g.matriz_ad[i][j];
        }

        void matriz_ad(){
            for(int i = 0; i < g.numvert; i++){
                for(int j = 0; j< g.numvert; j++){
                    if(g.matriz_ad[i][j] == INT_MAX){
                        printf("I ");
                    }else{
                        printf("%d ", g.matriz_ad[i][j]);
                    }
                }
                printf("\n");
            }
        }
};
int main(){
    int vezes, nvert,i,j,peso, casos, quests, k,som;
    scanf("%d", &vezes);
    casos = 0;
    while(vezes--){
        scanf("%d", &nvert);
        grafo g;
        g.create_graph(nvert,dir);
        casos++;

        for(i=0; i< nvert; i++){
            for(j=0; j< nvert; j++){
                scanf("%d", &peso);
                g.add_edge(i,j,peso);
            }
        }
        g.floyd_warshall();
        
        som = 0;
        scanf("%d", &quests);
        for(k = 0; k < quests; k++){
            scanf("%d %d", &i, &j);
            som += g.custo((i-1),(j-1));
        }
        printf("Case #%d: %d\n", casos,som);
    }
    return 0;
}