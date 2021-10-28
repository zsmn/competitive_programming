#include <bits/stdc++.h>
using namespace std;
typedef double ll;
#define endl "\n"

int main(){
    ll t; cin >> t;
    while(t--){
        ll r1,r2,x1,x2,y1,y2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll dx = abs(x1-x2);
        ll dy = abs(y1-y2);
        ll dc2 = pow(dx,2)+pow(dy,2);
        ll dc = sqrt(dc2);
        if(r1!=r2){
            ll dr = abs(r1-r2);
            if(dc == dr) cout << "E" << endl;
            else if(dc<dr) cout << "I" << endl;
            else cout << "O" << endl;
        }else if(x1==x2 && y1==y2) cout << "E" << endl;
        else cout << "O" << endl;
    }
    return 0;
}
