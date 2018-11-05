#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define inf 1e9
#define maxn 1000000

vector<int> graph[maxn];
int dist[maxn];
int have[maxn];

void dijkstra(int init){
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;	
	}
	if(have[init]) dist[init] = 0;
	else dist[init] = 1;
	priority_queue<ii, vector<ii>, greater<ii>> heap;
	heap.push(make_pair(dist[init], init));
	while(!heap.empty()){
		int cost = heap.top().first;
		int from = heap.top().second;
		heap.pop();
		
		if(cost > dist[from]) continue;
		
		for(int x = 0; x < graph[from].size(); x++){
			int di;
			if(have[graph[from][x]]) di = 0;
			else di = 1;
			int to = graph[from][x];
			if(dist[to] > dist[from] + di){
				dist[to] = dist[from] + di;
				heap.push(make_pair(dist[to], to));
			}
		}
	}
}

int qt;

void eraseAll(){
	for(int x = 0; x < qt; x++){
		graph[x].clear();
	}
	memset(have, 0, sizeof(have));
}

int main(){
	int n, aux = 1;
	cin >> n;
	while(n--){
		int cities, routes, have_air;
		cin >> cities >> routes >> have_air;
		for(int x = 0; x < have_air; x++){
			int aux; cin >> aux;
			have[aux] = 1;
		}
		for(int x = 0; x < routes; x++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		qt = cities;
		int q;
		cin >> q;
		cout << "Case " << aux << ":" << endl;
		for(int x = 0; x < q; x++){
			int a, b;
			cin >> a >> b;
			dijkstra(a);
			if(dist[b] != inf){
				if(a == b) cout << "0" << endl;
				else cout << dist[b] << endl;
			}else{
				cout << "-1" << endl;
			}
		}
		cout << endl;
		aux++;
		eraseAll();
	}
}
