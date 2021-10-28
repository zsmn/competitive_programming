#include <bits/stdc++.h>
#define endl "\n"
#define mod 1000000007
#define maxn 100002
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;

const ll INF = 1e9 + 7;

class Dinic{
	int N;
	vector<ll> level;
	vector<bool> dead;
	
public:
	struct Edge{
		Edge(int a,ll x){
			v = a;
			cap = x;
		}
		int v;
		ll cap;
	};
	int source;
	int sink;
	vector<Edge> edge;
	vector<vector<int>> g;

	Dinic(int n){
		g.resize(n);
		N = n;
		level.resize(n);
	}

	void setInit(int u,int v){
		source = u;
		sink = v;
	}

	void addEdge(int u,int v,ll cap){
		g[u].push_back(edge.size());
		edge.push_back(Edge(v,cap));
		g[v].push_back(edge.size());
		edge.push_back(Edge(u,0));
	}
private:

	bool BFS(){
		
		for(int i=0;i<N;i++) level[i] = INF;
		dead.clear();
		dead.resize(N, false);
		level[source] = 0;
		queue<int> q;
		q.push(source);

		while(!q.empty()){

			int u = q.front();
			q.pop();

			if(u == sink) return true;

			for(auto x: g[u]){
				if(level[edge[x].v] == INF && edge[x].cap > 0){
					level[edge[x].v] = level[u] + 1;
					q.push(edge[x].v);
				}
			}
		}
		return false;
	}

	ll maxflow(int u,ll flow){
		
		if(dead[u]) return 0;

		ll ret = 0;
		ll f = 0;
		if(flow == 0) return 0;
		if(u == sink) return flow;

		for(auto i: g[u]){
			if(level[edge[i].v] != level[u] + 1) continue;
			f = maxflow(edge[i].v,min(edge[i].cap,flow));
			int x = (i%2 == 0?i+1:i-1);
			flow -= f;
			ret += f;
			edge[i].cap -= f;
			edge[x].cap += f;
		}
		
		if(ret == 0) dead[u] = true;
		
		return ret;
	}
public:
	ll run(){

		ll flow = 0;
		while(BFS()){
			flow += maxflow(source,INF);
		}

		return flow;
	}
};

struct aresta{
    int a,b;
    ll peso;
    aresta(int _a, int _b, int _c): a(_a), b(_b), peso(_c){}
};

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int p,r,c;
    cin >> p >> r >> c;
    vector<ll> posto,refin;
    vector<aresta> rota;
    int s = p;
    ll soma = 0;
    while(s--){
        ll a; cin >> a;
        soma += a;
        posto.push_back(a);
    }
    s = r;
    while(s--){
        ll a; cin >> a;
        refin.push_back(a);
    } 
    s = c;
    while(s--){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        rota.push_back(aresta(a-1,b-1,c));
    }
    int qtd = p+r;
    int sou = qtd, sink = qtd+1;
    //cout << "hueheuheu\n";
    int le = 0, ri = 1000001, ans = -1;
    int m;
    //return 0;
    ll maior = 0;
    while(le <= ri){
        m = (le+ri)/2;
        Dinic dini = Dinic(qtd+2);

        dini.setInit(sou,sink);


        for(int i=0; i<p; i++){
            dini.addEdge(i,sink,posto[i]);
        }

        for(int i=p; i<p+r; i++){
            dini.addEdge(sou,i,refin[i-p]);
        }

        for(int i=0; i<rota.size(); i++){
            if(rota[i].peso <= m){
                dini.addEdge(rota[i].b+p, rota[i].a, refin[rota[i].b]);
            }
        }

        maior = dini.run();
        if(maior == soma){
            ans = m;
            ri = m-1;
        }else{
            le = m+1;
        }
    }

    cout << ans << endl;
    
}
