#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ll n, p, w, d;
    scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
    //x*w + y*d = p
    // x + y + z = n
    ll a = gcd(w, d);
    if(p%a!=0){
        printf("-1\n");
        return 0;
    }
    ll x, y = 0, z;
    bool achei = false;
    for(y=0;y<w;y++){
        x = (p - y*d)/w;
        if((p-y*d)%w || x<0 || x+y>n) continue;
        z = n - y - x;
        printf("%lld %lld %lld\n", x, y, z);
        achei = true;
        break;
    }
    if(!achei) printf("-1\n");
    return 0;
}