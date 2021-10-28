#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define endl "\n"
#define par 0
#define impar 1

int main(){
    string s;
    cin >> s;
    stack<char> p;
    bool a=false;
    for(int i=0; i<s.size();i++){
        if(p.empty()) p.push(s[i]);
        
        else{
                if(p.top()==s[i]){
                p.pop();
                a = !a;
            }else{
                p.push(s[i]);
            }
        }
        
    }
    if(a) cout << "YES";
    else cout << "NO";
    return 0;
}
