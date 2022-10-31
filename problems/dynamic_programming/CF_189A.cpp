#include <bits/stdc++.h>
using namespace std;
#define mini -1000000000
typedef long long ll;
ll dp[5000];
ll vis[5000];
vector<ll> values;

ll solve(ll val){
    dp[0] = 0;
    vis[0] = true;
    if(val < 0)return mini;
    if(vis[val])return dp[val];
    vis[val] = true;
    ll mai = mini;
    for(int v : values){
        mai = max(mai,solve(val-v));
    }
    dp[val] = 1+mai;
    return dp[val];
}

int main(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    values.push_back(a);
    values.push_back(b);
    values.push_back(c);
    cout << solve(n) << endl;
    return 0;
}
