#include<bits/stdc++.h>
using namespace std;
 
int main(){
    vector<int> a;
    vector<int> b;
 
    int n;
    cin >> n;
 
    for(int x = 0; x < n; x++){
        int aux; cin >> aux;
        a.push_back(aux);
        b.push_back(aux);
    }
 
    sort(b.begin(), b.end());
 
    int init_fake = 0;
    int end_fake = 0;
    int init = 0;
    int end = 0;
 
    for(int x = 0; x < n - 1; x++){
        if(a[x] > a[x+1]){
            end_fake = x + 1;
        }
        else{
            init_fake = x + 1;
            end_fake = x + 1;
        }
 
        if(end_fake - init_fake > end - init){
            end = end_fake;
            init = init_fake;
        }
    }
 
    reverse(a.begin() + init, a.begin() + end + 1);
/*
    for(int x = 0; x < n; x++){
        cout << a[x] << " ";
    }
    cout << endl << endl << endl;
    cout << init << " " << end << endl;
*/
    bool c = true;
    for(int x = 0; x < n && c; x++){
        if(a[x] != b[x]) c = false;
    }
 
    if(c){
        cout << "yes" << endl;
        cout << init+1 << " " << end+1 << endl;
    }else{
        cout << "no" << endl;
    }
}
