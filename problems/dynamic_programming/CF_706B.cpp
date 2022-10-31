#include <bits/stdc++.h>
using namespace std;
#define mini -1000000000
typedef long long ll;
ll dp[112345];
ll vis[112345];
ll freq[112345];

ll solve(){
    for(int i=1; i<=100000; i++){
        dp[i] = dp[i-1] + freq[i];
    }
}

int main(){
    ll n,q;
    cin >> n;
    for(int i=0; i<n; i++){
        int a; scanf("%d", &a);
        freq[a]++;
    }
    solve();
    cin >> q;
    while(q--){
        int a; scanf("%d", &a);
        a = min(a,100000);
        printf("%lld\n", dp[a]);
    }
    return 0;
}
