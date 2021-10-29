#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long int ll;
typedef pair<ll, ll> ii;

ll mode;
const int m = 4;
typedef struct Matrix{ 
    ll mat[m][m];
    Matrix operator * (const Matrix &p) {
        Matrix ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=ans.mat[i][j]=0;k<m;k++){
                    ans.mat[i][j] += (mat[i][k]*p.mat[k][j])%mode;
                }
                ans.mat[i][j] %= mode;
            }
        }
        return ans;
    }
}Matriz;

Matrix fExp(Matrix a, ll b) {
    Matrix ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) ans.mat[i][j] = 1;
            else ans.mat[i][j] = 0;
        }
    }
    while(b!=0){
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main (){

    ll casos;
    scanf("%lld", &casos);
    while(casos--){
        ll n;
        scanf("%lld %lld", &n, &mode);
        Matriz a, b;
        for(int i=0;i<m;i++) for(int j=0;j<m;j++){
            a.mat[i][j] = 0, b.mat[i][j] = 0;
        }
        a.mat[0][0] = 1, a.mat[0][2] = 1, a.mat[0][3] = 1;
        b.mat[0][0] = 1, b.mat[0][1] = 1, b.mat[1][0] = 1;
        b.mat[2][0] = 1, b.mat[2][2] = 1, b.mat[3][2] = 1, b.mat[3][3] = 1; 
        if(n==0) printf("0\n");
        else if(n==1) printf("1\n");
        else{
            Matriz ans = a * fExp(b, n-1);
            printf("%lld\n", ans.mat[0][0]);
        }
    }
    return 0;
}