#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll vec[5] = {100,20,10,5,1};

int main(){
    ll n;
    cin >> n;
    ll tot = 0;
    for(int i=0; i<5; i++){
        tot += n/vec[i];
        n = n%vec[i];
    }
    cout << tot << endl;
    return 0;
}
