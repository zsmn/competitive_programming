#include <bits/stdc++.h>
using namespace std;
#define mini -1000000000
typedef long long ll;
ll dp[112345];
ll vis[112345];
ll freq[112345];

ll solve(){
    for(int i=100001; i>=0; i--){
        dp[i] = max((freq[i]*i) + dp[i+2], dp[i+1]);
    }
}

int main(){
    ll n;;
    cin >> n;
    for(int i=0; i<n; i++){
        int a; scanf("%d", &a);
        freq[a]++;
    }
    solve();
    cout << dp[0] << endl;
    return 0;
}
