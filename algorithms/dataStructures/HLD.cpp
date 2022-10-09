#include "bits/stdc++.h"
using namespace std;

#define mp make_pair

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

vector<vector<ii> > adj;

class HLD{
    int N;

    vector<int> tree;

    vector<int> sz;
    vector<int> pos;
    vector<int> head;
    vector<int> level;
    vector<int> parent;

    int query(int p, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return 0;
        else if(ql <= l && r <= qr) return tree[p];

        int mid = (l + r) >> 1;
        int lc = 2*p, rc = lc + 1;

        return max(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
    }

    void update(int p, int l, int r, int pos, int w){
        if(l == r){
            tree[p] = w;
            return;
        }

        int mid = (l + r) >> 1;
        int lc = 2*p, rc = lc + 1;

        if(pos <= mid) update(lc, l, mid, pos, w);
        else update(rc, mid + 1, r, pos, w);

        tree[p] = max(tree[lc], tree[rc]);
    }

    void dfs(int u, int lvl){
        sz[u] = 1;
        level[u] = lvl;
        int bigChild = 0;

        for(auto &cur: adj[u]){
            int v = cur.first;
            if(v == parent[u]) continue;
            parent[v] = u;

            dfs(v, lvl + 1);

            sz[u] += sz[v];

            if(sz[v] > bigChild){
                swap(cur, adj[u][0]);
            }
            bigChild = max(bigChild, sz[v]);
        }
    }

    void decompose(int u, int &x, bool keep){
        if(keep) head[u] = head[parent[u]];
        else head[u] = u;

        pos[u] = x++;

        if(sz[u] > 1) decompose(adj[u][0].first, x, true);

        for(int i = 1; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            if(v == parent[u]) continue;
            decompose(v, x, 0);
        }
    }

    public:
        HLD(int n){
            N = n;
            adj.resize(n+5);
            sz.assign(n+5, -1);
            pos.assign(n+5, -1);
            head.assign(n+5, -1);
            level.assign(n+5, -1);
            parent.assign(n+5, -1);
            tree.assign(4*n + 5, 0);
        }

        void addEdge(int u, int v, int w){
            adj[u].push_back(mp(v, w));
            adj[v].push_back(mp(u, w));
        }

        void init(){
            parent[0] = -1;
            dfs(0, 0);
            int x = 0;
            decompose(0, x, 0);
        }

        int LCA(int u, int v){
            while(head[u] != head[v]){
                if(level[head[u]] > level[head[v]]) u = parent[head[u]];
                else v = parent[head[v]];
            }
            return ((level[u] < level[v]) ? u : v);
        }

        int solve(int u, int v){
            if(level[u] < level[v]) swap(u, v);

            int ans = 0;

            while(head[u] != head[v]){
                ans = max(ans, query(1, 0, N-1, pos[head[u]], pos[u]));
                u = parent[head[u]];
            }

            ans = max(ans, query(1, 0, N-1, pos[v] + 1, pos[u]));

            return ans;
        }

        int get(int u, int v){
            int l = LCA(u, v);
            return max(solve(u, l), solve(v, l));
        }

        void flip(int u,int w){
            update(1, 0, N-1, pos[u], w);
        }

        int which(int u, int v){
            return (level[u] > level[v] ? level[u] : level[v]); 
        }

        int lenPath(int u,int v){
            int l = LCA(u,v);
            int ret = level[u] - level[l];
            ret += level[v] - level[l];
            ret++;
            return ret;
        }
};
