#include<bits/stdc++.h>
using namespace std;
 
int main(){
     int winnerAt = 0;
     string c;
     cin >> c;
 
     stack<char> s;
 
     for(int x = 0; x < c.length(); x++){
          if(!s.empty() && s.top() == c[x]){
               s.pop();
               winnerAt++;
          }else{
               s.push(c[x]);
          }
     }
     
     if(winnerAt % 2 == 1) cout << "Yes" << endl;
     else cout << "No" << endl;
}
