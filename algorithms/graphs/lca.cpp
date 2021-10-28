#include <bits/stdc++.h>
#define endl "\n"
#define mod 1000000007
#define maxn 100002
#define all(x) x.begin(), x.end()
using namespace std;

const int level = 18; //log2(maxn) pelo menos

vector<int> adj[maxn];
int parent[maxn][level];
int depth[maxn];
int n;

void dfs(int atu, int pre){
    depth[atu] = depth[pre]+1;
    parent[atu][0] = pre;
    for(auto el : adj[atu]){
        if(el == pre)continue;
        dfs(el,atu);
    }
}

void processing(){
    for(int l=1; l<level; l++){
        for(int no=0; no<n; no++){
            if(parent[no][l-1] != -1){
                parent[no][l] = parent[parent[no][l-1]][l-1];
            }
        }
    }
}

int lca(int u, int v){
    if(depth[v] < depth[u])swap(u,v);
    int diff = depth[v] - depth[u];

    //faça o v subir agora
    for(int i=level-1; i>=0; i--){
        if((diff>>i)&1){
            v = parent[v][i];
        }
    }
    
    //u e v estão no mesmo nível
    if(u == v)return u;

    for(int i=level-1; i>=0; i--){
        if(parent[v][i] != parent[u][i]){
            v = parent[v][i];
            u = parent[u][i];
        }
    }

    return parent[u][0];
}

int distance(int u, int v){ 
    /*
        Retorna o número de arestas que se tem que percorrer para chegar de u a v
    */
    int ancestor = lca(u,v);
    int dista = ((depth[u]-1) + (depth[v]-1)) - ((depth[ancestor]-1)<<1);
    return dista;
}

int verticesInter(int u, int v){
    /*
        Retorna o número de vertices que tem entre u e v, excluindo u e v;
    */
    int dist = distance(u,v);
    if(dist <= 1)return 0;
    return dist-1;
}

void reseta(int root = 0, bool isOneBased = false){
    if(isOneBased)n++;
    memset(parent,-1,sizeof(parent));
    dfs(root,root-1);
    processing();
}

void add(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main(){
    int q;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;
        add(a,b);
    }
    reseta();
    for(int i=0; i<q; i++){
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a--; b--; c--; d--;
        int dab = distance(a,b);
        int ancestral = lca(a,b);
        //cout << "lca de " << a+1 << " e " << b+1 << " = " << 1+ancestral << endl;
        //cout << "depth: " << depth[a] << " " << depth[b] << " " << depth[ancestral] << endl; 
        int dcd = distance(c,d);
        int removea = ((distance(a,c) + distance(a,d)) - dcd)/2;
        int removeb = ((distance(b,c) + distance(b,d)) - dcd)/2;
        int removec = ((distance(c,a) + distance(c,b)) - dab)/2;
        int removed = ((distance(d,a) + distance(d,b)) - dab)/2;
        int inter2 = (dab + dcd) - (removea + removeb + removec + removed);
        int inter = inter2/2;
        if(inter2 < 0){
            printf("0\n");
        }else{
            printf("%d\n",inter+1);
        }
        //cout << removea << " " << removea << " " << removea << " " << removea << " " << inter2 << " " << inter << " " << dab << " " << dcd << " " << (dab + dcd) << "\n";
    }
    return 0;
}
