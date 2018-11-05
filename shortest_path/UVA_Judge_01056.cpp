#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define mp(a, b) make_pair(a, b)

const int inf = 1e9;
const int maxn = 10000;
vector<ii> grafo[10000];
int dist[maxn];
map<string, int> mp;
int n = 1;

void add_Aresta(int deonde, int praonde){
	grafo[deonde].push_back(mp(1, praonde));
	grafo[praonde].push_back(mp(1, deonde));
}

void dijkstra(string inicio){
	/* seta todas as distancias inicialmente como infinito */
	/* obs.: infinito aqui significa que não tem como chegar 
	nesse vertice em específico! */
	
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;
	}
	/* aqui criamos a heap, é greater, logo ela vai colocar os
	menores pares no topo. obs.:
	eu utilizo o pair<custo, vertice> porque ele ordena pelo 
	primeiro elemento, logo como quero o menor custo, assim é
	worth.
	*/
	
	priority_queue<ii, vector<ii>, greater<ii> > heap;
	dist[mp[inicio]] = 0; // seto a distancia do vertice incial como 0
	heap.push(mp(0, mp[inicio])); // dou push na heap com o par <custo, vertice> iniciais
	while(!heap.empty()){
		int distancia, praonde;
		distancia = heap.top().first; // distancia é o primeiro elemento do par
		deonde = heap.top().second; // deonde é o segundo elemento do par
		heap.pop(); // dou pop (como ja vou analisar agora, nao preciso mais armazenar)
		// se a distancia da aresta ja eh maior que a propria distancia ate esse vertice, foda-se
		if(distancia > dist[deonde]){
			continue;
		}
		// aqui esse for vai analisar todas as arestas conectadas ao vertice 'deonde'
		for(int x = 0; x < (int) grafo[deonde].size(); x++){
			int d, i;
			/* aqui ele armazena o peso de cada aresta e pra que vertice leva */
			d = grafo[deonde][x].first; // peso
			i = grafo[deonde][x].second; // pra onde vai
			/* aqui vem a magica:
			Se a distancia ate o vertice que voce ta analisando + a distancia da aresta
			ate um outro vertice for menor que a distancia associada a esse vertice para
			onde voce está indo, logo podemos substituir essa distancia pela menor, que
			encontramos. */
			/* obs.: logo após isso, jogamos na heap novamente, já que como descobrimos
			um menor caminho até esse vértice, temos que calcular novamente todos os outros
			vértices conectados a ele pelas arestas. */
			if(dist[deonde] + d < dist[i]){
				dist[i] = dist[deonde] + d;
				heap.push(mp(dist[i], i));
			}
		}
	}
}

void zerar_grafo(){
    for(int x = 1; x < maxn; x++){
        grafo[x].clear();
    }
}

int main(){
	int vert, ar, cont, aux = 0;

	while(cin >> vert >> ar && (vert != 0 && ar != 0)){
		aux++;
		n = vert;
		mp.clear();
		zerar_grafo();
		cont = 1;
		for(int x = 0; x < ar; x++){
			string deonde, praonde;
			cin >> deonde >> praonde;
			if(mp[deonde] == 0){
				mp[deonde] = cont++;
			}
			if(mp[praonde] == 0){
				mp[praonde] = cont++;
			}
			add_Aresta(mp[deonde], mp[praonde]);
		}
		int best = 0;
		for (auto& kv : mp) {
			//cout << "analisando: " << kv.first << endl;
			dijkstra(kv.first);
			for(int x = 1; x <= vert; x++){
				if(dist[x] == 1e9){
				    best = -1;
					break;
				}
				if(dist[x] > best){
					best = dist[x];
				}
			}
		}
		if(best == -1){
			cout << "Network " << aux << ": DISCONNECTED" << endl << endl;
		}else{
			cout << "Network " << aux << ": " << best << endl << endl;
		}
	}
}
