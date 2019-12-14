#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp(a, b) make_pair(a, b)

vector<ii> grafo[100000];
const int inf = 1e9;
const int maxn = 100000;

int n = 0;
int dist[maxn];

void dijkstra(int inicio){
	for(int x = 0; x < n; x++){
		dist[x] = inf;
	}
	priority_queue<ii, vector<ii>, greater<ii> > heap;
	dist[inicio] = 0;
	heap.push(mp(dist[inicio], inicio));
	while(!heap.empty()){
		int distancia, index;
		distancia = heap.top().first;
		index = heap.top().second;
		//tie(distancia, index) = heap.top();
		heap.pop();
		if(distancia > dist[index]){
			continue;
		}
		for(int x = 0; x < (int) grafo[index].size(); x++){
			int d, p_onde;
			d = grafo[index][x].first;
			p_onde = grafo[index][x].second;
			//tie(d, p_onde) = grafo[index][x];
			if(dist[index] + d < dist[p_onde]){
				dist[p_onde] = dist[index] + d;
				heap.push(mp(dist[p_onde], p_onde));
			}
		}
	}
}

void add_Aresta(int qual, int onde, int valor){
	grafo[qual].push_back(mp(valor, onde));
	grafo[onde].push_back(mp(valor, qual));
}

void zerar_Grafo(){
	for(int x = 0; x < n; x++){
        grafo[x].clear();
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int qt_testes;
	cin >> qt_testes;
    int aux = 0;
	while(qt_testes--){
        aux++;
        zerar_Grafo();
		int qt, arestas, a , b;
		cin >> qt >> arestas >> a >> b;
		n = qt;
		for(int x = 0; x < arestas; x++){
			int deonde, praonde, peso;
			cin >> deonde >> praonde >> peso;
			add_Aresta(deonde, praonde, peso);
		}
		dijkstra(a);

		if(dist[b] == inf){
			cout << "Case #" << aux << ": unreachable" << endl;
		}else{
			cout << "Case #" << aux << ": " << dist[b] << endl;
		}
		if(qt_testes == 0){
			break;
		}
	}
}
