typedef long long ll;
const ll INF = 1e18 + 5;

ll dist[N][N];

void floyd(){
    //Inicializando
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    //Arestas
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    //DP
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}
