#include<bits/stdc++.h>
using namespace std;
#define maxn 1000009
#define inf 1e9
typedef pair<int, int> ii;

vector<ii> grafo[maxn];
int dist[maxn];
vector<int> mat[maxn];
int a1, a2;
int didi;

void dijkstra(int init){
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;
	}
	priority_queue<ii, vector<ii>, greater<ii>> heap;
	dist[init] = didi;
	heap.push(make_pair(dist[init], init));
	
	while(!heap.empty()){
		int index = heap.top().second;
		int value = heap.top().first;
		heap.pop();
		if(value > dist[index]) continue;
		for(int x = 0; x < grafo[index].size(); x++){
			int d = grafo[index][x].first;
			int i = grafo[index][x].second;
			if(d + dist[index] < dist[i]){
				dist[i] = d + dist[index];
				heap.push(make_pair(dist[i], i));
			}
		}
	}
}

void generateConnections(){
	int cont = 0;
	for(int x = 0; x < a1; x++){
		for(int y = 0; y < a2; y++){
			if(y - 1 >= 0) grafo[cont].push_back(make_pair(mat[x][y-1], cont - 1)); // cont - 1
			if(x - 1 >= 0) grafo[cont].push_back(make_pair(mat[x-1][y], cont - a2)); // cont - a2
			if(y + 1 < a2) grafo[cont].push_back(make_pair(mat[x][y+1], cont + 1)); // cont + 1
			if(x + 1 < a1) grafo[cont].push_back(make_pair(mat[x+1][y], cont + a2)); // cont + a2
			cont++;
		}
	}
}

void zerarGrafo(){
	for(int x = 0; x < maxn; x++){
		grafo[x].clear();
	}
	for(int x = 0; x < maxn; x++){
		mat[x].clear();
	}
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int p, m;
		cin >> p >> m;
		
		for(int x = 0; x < p; x++){
			for(int y = 0; y < m; y++){
				int aux; cin >> aux;
				mat[x].push_back(aux);
			}
		}
		
		a1 = p;
		a2 = m;
		didi = mat[0][0];
		
		generateConnections();
		dijkstra(0);
		
		int last = (p*m) - 1;
		cout << dist[last] << endl;
		
		zerarGrafo();
	}
}
