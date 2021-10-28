#include <bits/stdc++.h>
using namespace std;

string tirar(string s){
    
    for (int i=0; i<s.size(); i++){
        if((s[i]!='-' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z'){
            s.erase(remove(s.begin(),s.end(),s[i]));
        }
    }
    return s;
}

int main(){
    string s;
    int m = 0;
    cin >> s;
    string r = "";    
    while(s != "E-N-D"){
        s = tirar(s);
        if(s.size()>r.size()){
            r = s;
        }
        cin >> s;
    }
    for(int i=0; i<r.size(); i++){
        if(r[i]>='A' && r[i]<='Z') r[i] += 32;
    }
    cout << r << endl;
    return 0;
}
