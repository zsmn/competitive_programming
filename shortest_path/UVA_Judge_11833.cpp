#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define inf 1e9
typedef pair<int, int> ii;

vector<ii> graph[maxn];
int dist[maxn];

int C;

int dijkstra(int init, int end){
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;
	}
	dist[init] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> heap;
	heap.push(ii(dist[init], init));
	while(!heap.empty()){
		int from = heap.top().second;
		int cost = heap.top().first;
		heap.pop();
		if(cost > dist[from]) continue;
		for(int x = 0; x < (int) graph[from].size(); x++){
			int to = graph[from][x].second;
			int cf = graph[from][x].first;
			if(from < C){
				if(to == from + 1 && cf + dist[from] < dist[to]){
					dist[to] = dist[from] + cf;
					heap.push(ii(dist[to], to));
				}
			}
			else if(cf + dist[from] < dist[to]){
				dist[to] = cf + dist[from];
				heap.push(ii(dist[to], to));
			}
		}
	}
	return dist[end];
}

int main(){
	int n, m, c, k;
	while(1){
		cin >> n;
		cin >> m;
		cin >> c;
		cin >> k;
		if(n == 0){
			return 0;
		}
		C = c;
		
		for(int x = 0; x < m; x++){
			int r, t, s;
			cin >> r >> t >> s;
			graph[r].push_back(ii(s, t));
			graph[t].push_back(ii(s, r));
		}
		
		cout << dijkstra(k, c-1) << endl;
		
		for(int x = 0; x < n; x++){
			graph[x].clear();
		}		
	}
}
