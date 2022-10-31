#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    vector<long long> v;
    cin >> n;
 
    long long at_gcd = 0;
    long long maior_elem = 0;
 
    for(int x = 0; x < n; x++){
        long long a; cin >> a;
        v.push_back(a);
        maior_elem = max(maior_elem, a);
    }
 
    long long sum_dif = 0;
 
    for(int x = 0; x < n; x++){
        at_gcd = __gcd(at_gcd, abs(v[x] - maior_elem));
        sum_dif += abs(v[x] - maior_elem);
    }
 
    cout << (long long) sum_dif/at_gcd << " " << at_gcd << endl;
 
}
