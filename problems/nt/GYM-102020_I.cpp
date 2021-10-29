#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll gcd_ext(ll a, ll b, ll& x, ll& y) {
 if (b == 0) {
   x = 1, y = 0;
   return a;
 }
 ll nx, ny;
 ll gc = gcd_ext(b, a%b, nx, ny);
 x = ny;
 y = nx - (a / b) * ny;
 return gc;
}

int main(){
    ll a, b, n;
    bool flag = false;
    scanf("%lld %lld", &a, &b);
    scanf("%lld", &n);
    ll vet[n];
    vector<ll> resp1, resp2;
    for(ll i=0;i<n;i++) scanf("%lld", &vet[i]);
    if(a==b){
        for(ll i=0;i<2*n;i++) printf("0\n");
        return 0;
    }
    if(n==1){
        ll c1 = (a-b)/vet[0];
        ll c2 = (b-a)/vet[0];
        if(a>b) printf("0\n%lld\n", c1);
        else printf("%lld\n0\n", c2);
        return 0;
    } 
    if(a>b) flag = true, swap(a, b); 
    ll r = b-a, N=n-1;
    ll mdc[n] = {};
    for(int i=0;i<n;i++){
        if(i==0) mdc[i] = vet[i];
        else mdc[i] = gcd(vet[i], mdc[i-1]);
    }
    while(N>0){
        ll aux = mdc[N-1];
        ll x, y;
        ll gc = gcd_ext(aux, vet[N], x, y);
        x *= r/gc, y *= r/gc;
        if(abs(x)>1e9){
            ll k; // x1 = x + vet[n]*k
            if(x>0) k = (1e9 - x)/vet[N] - 1;
            else k = ((-1)*1e9 - x)/vet[N] + 1;
            x = x + vet[N]*k;
            y = y - aux*k;
        } if(abs(y)>1e9){
            ll k;
            if(y>0) k = (1e9 - y)/aux - 1;
            else k = ((-1)*1e9 - y)/aux + 1;
            y = y + aux*k;
            x = x - vet[N]*k;
        }
        if(y>0) resp1.push_back(y), resp2.push_back(0);
        else resp1.push_back(0), resp2.push_back(-1*y);
        if(N==1){
            if(x>0) resp1.push_back(x), resp2.push_back(0);
            else resp1.push_back(0), resp2.push_back(-1*x);
        }
        r = x*aux; N--; 
    }
    if(!flag){
        for(int i=n-1;i>=0;i--){
            printf("%lld\n", resp1[i]);
        }
        for(int i=n-1;i>=0;i--){
            printf("%lld\n", resp2[i]);
        }
    } else{
        for(int i=n-1;i>=0;i--){
            printf("%lld\n", resp2[i]);
        }
        for(int i=n-1;i>=0;i--){
            printf("%lld\n", resp1[i]);
        }
    }
    return 0;
}