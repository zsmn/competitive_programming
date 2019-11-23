#include<bits/stdc++.h>
using namespace std;

int main(){
    int vet[101];
    long long int total;
    int n;
    cin >> n;
    for(int x = 0; x < n; x++){
        int aux; cin >> aux;
        total += aux;
        vet[x] = aux;
    }

    if(total & 1) cout << "NO" << endl;
    else{
        bool can = false;
        for(int x = 0; x < n; x++){
            int a1 = vet[x], a2 = 0;
            for(int y = 0; y < n; y++){
                if(y == x) continue;
                if(a1 < a2) a1 += vet[y];
                else a2 += vet[y];
            }
            if(a1 == a2){
                can = true;
                break;
            }
        }
        if(can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
