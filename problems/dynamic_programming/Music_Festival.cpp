#include <bits/stdc++.h>
#define endl "\n"
#define mod 1000000007
#define all(x) x.begin(), x.end()
using namespace std;
 
struct show{
    int in, fi;
    int val, st;
    show(int _in, int _fi, int _val, int _st){
        in = _in;
        fi = _fi;
        val = _val;
        st = _st;
    }
    string toStr(){
        string s = "";
        s += "in: " + to_string(in) + " fi: " + to_string(fi) + " val: " + to_string(val) + " st: " + to_string(st);
        return s; 
    }
};
 
vector<vector<show>> stage;
vector<int> tempos;
map<int,int> valor;
int dp[1100][2100];
bool vis[1100][2100];
 
int resolve(int mask, int tempo){
    if(vis[mask][tempo]){
        return dp[mask][tempo];
    }
    vis[mask][tempo] = true;
    if(mask == 0){
        dp[mask][tempo] = 0;
        return 0;
    }
    if(tempo == 0){
        dp[mask][tempo] = -1;
        return -1;
    }
    int atual = -1;
    for(int i=0; i<stage.size(); i++){
        if(mask & (1<<i)){
            for(auto p : stage[i]){
                if(p.fi == tempo){
                    int auxa = resolve(mask,p.in);
                    int val1 = -1;
                    if(auxa != -1){
                        val1 = auxa + p.val;
                    }
                    int auxi = resolve(mask ^ (1<<i),p.in);
                    int val2 = -1;
                    if(auxi != -1){
                        val2 = auxi + p.val;
                    }
                    atual = max(atual,val1);
                    atual = max(atual,val2);
                }
            }
        }
    }
    atual = max(atual,resolve(mask,tempo-1));
    dp[mask][tempo] = atual;
    return atual;
}
 
int cmp(show a, show b){
    if(a.in < b.in)return 1;
    if(b.in < a.in)return 0;
    if(a.fi < b.fi)return 1;
    if(b.fi < a.fi)return 0;
    if(a.val < b.val)return 1;
    return 0;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int stg;
    cin >> stg;
    for(int i=0; i<stg; i++){
        int sh; cin >> sh;
        stage.push_back(vector<show>());
        for(int j=0; j<sh; j++){
            int a,b,c; cin >> a >> b >> c;
            tempos.push_back(a);
            tempos.push_back(b);
            stage[i].push_back(show(a,b,c,i));
        }
    }
 
    sort(all(tempos));
    tempos.resize(unique(all(tempos)) - tempos.begin());
    for(int i=0; i<tempos.size(); i++){
        valor[tempos[i]] = i;    
    }
 
    for(int i=0; i<stg; i++){
        sort(all(stage[i]),cmp);
    }
 
    for(int i=0; i<stage.size(); i++){
        for(int j=0; j<stage[i].size(); j++){
            stage[i][j].in = valor[stage[i][j].in];
            stage[i][j].fi = valor[stage[i][j].fi];
            //cout << stage[i][j].toStr() << endl;
        }
    }
    
    int mascara = 0;
    for(int i=0; i<stage.size(); i++){
        mascara = mascara | (1<<i);
    }
 
    cout << resolve(mascara,valor[tempos[tempos.size()-1]]) << endl;
    /*
    for(int i=0; i<=mascara; i++){
        for(int j=0; j<=valor[tempos[tempos.size()-1]]; j++){
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }*/
    return 0;
}
