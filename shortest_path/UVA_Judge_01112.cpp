#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define maxn 10000
#define inf 1e9+1

vector<ii> grafo[maxn];
int dist[maxn];

void dijkstra(int init){
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;
	}
	priority_queue<ii, vector<ii>, greater<ii>> heap;
	dist[init] = 0;
	heap.push(make_pair(dist[init], init));
	while(!heap.empty()){
		int d = heap.top().first;
		int index = heap.top().second;
		heap.pop();
		if(d > dist[index]){
			continue;
		}
		for(int x = 0; x < (int) grafo[index].size(); x++){
			int d = grafo[index][x].first;
			int p_onde = grafo[index][x].second;
			if(d + dist[index] < dist[p_onde]){
				dist[p_onde] = d + dist[index];
				heap.push(make_pair(dist[p_onde], p_onde));
			}
		}
	}
}

void zerarGrafo(){
	for(int x = 0; x < maxn; x++){
		grafo[x].clear();
	}
}

void addAresta(int deonde, int praonde, int custo){
	grafo[deonde].push_back(make_pair(custo, praonde));
}

int main(){
	int n;
	cin >> n;
	string str;
	
	while(n--){
		getline(cin, str);
		int n_cells, e_cell, t;
		cin >> n_cells >> e_cell >> t;
		int n_vertices;
		cin >> n_vertices;
		while(n_vertices--){
			int a, b, c;
			cin >> a >> b >> c;
			addAresta(a, b, c);
		}
		int caux = 0;
		int cont = 1;
		while(n_cells--){
			dijkstra(cont);
			if(dist[e_cell] <= t){
				caux++;
			}
			cont++;
		}
		if(n == 0) cout << caux << endl;
		else cout << caux << endl << endl;
		zerarGrafo();
	}
}
