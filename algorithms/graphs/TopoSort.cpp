bool toposort(vector <vector <int>>& grafo) {
    vector<int> lista;
    for(int i = 0; i <grafo.size(); i++) if(grau[i] == 0) lista.pb(i);
    int ini = 0;
    while(ini < lista.size()){
        int atual = lista[ini];
        ini++;
        for(int i = 0; i < grafo[atual].size(); i++){
            int v = grafo[atual][i];
            grau[v]--;
            if(grau[v]==0){
                lista.push_back(v);  
            } 
        }
    }
    if(lista.size() < grafo.size()) return false;
    else{
        for(int i = 0; i < grafo.size(); i++){
            if(i == 0)cout << lista[i];
            else cout << ' ' << lista[i];
        }
        cout << endl;
    }
    return true;
}
