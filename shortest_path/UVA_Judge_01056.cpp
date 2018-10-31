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
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;
	}
	priority_queue<ii, vector<ii>, greater<ii> > heap;
	dist[mp[inicio]] = 0;
	heap.push(mp(0, mp[inicio]));
	while(!heap.empty()){
		int distancia, praonde;
		distancia = heap.top().first;
		praonde = heap.top().second;
		heap.pop();
		if(distancia > dist[praonde]){
			continue;
		}
		for(int x = 0; x < (int) grafo[praonde].size(); x++){
			int d, i;
			d = grafo[praonde][x].first;
			i = grafo[praonde][x].second;
			if(dist[praonde] + d < dist[i]){
				dist[i] = dist[praonde] + d;
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
