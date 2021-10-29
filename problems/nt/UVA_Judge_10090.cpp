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
    ll n;
    scanf("%lld", &n);
    while(n!=0){
        ll c1, c2, n1, n2;
        scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
        ll x, y;
        ll gc = gcd_ext(n1, n2, x, y);
        if(n%gc!=0){
            printf("failed\n");
            scanf("%lld", &n);
            continue;
        } //x1 = x + n2*k
        x *= n/gc, y *= n/gc;
        //printf("gcd=%lld x=%lld y=%lld\n", gc, x, y);
        ll N2 = n2/gc;
        ll N1 = n1/gc;
        double aux = ((double)c1/(double)n1) - ((double)c2/(double)n2);
        if(aux>0.0){
            ll k = (-1*x)/N2;
            if((x + N2*k)<0) k++;
            x = x + N2*k;
            y = y - N1*k;
            //printf("new x=%lld y=%lld\n", x, y);
            if(y<0 || x<0){
                printf("failed\n");
                scanf("%lld", &n);
                continue;
            }
        } else{
            ll k = (-1*y)/N1;
            if((y + N1*k)<0) k++;
            y = y + N1*k;
            x = x - N2*k;
            //printf("new x=%lld y=%lld\n", x, y);
            if(x<0 || y<0){
                printf("failed\n");
                scanf("%lld", &n);
                continue;
            }
        }
        printf("%lld %lld\n", x, y);
        scanf("%lld", &n);
    }
    return 0;
}