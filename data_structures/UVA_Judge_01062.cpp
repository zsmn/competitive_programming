#include<bits/stdc++.h>
using namespace std;

stack<char> p;
vector<stack<char>> v;

int main(){
    int ans, flag = 0, t = 1;
    string s;

    while(cin >> s && s != "end"){
        ans = 0;
        flag = 0;
        v.clear();
        for(int x = 0; x < s.length(); x++){
            for(int y = 0; y < v.size(); y++){
                if(s[x] <= v[y].top()){
                    v[y].push(s[x]);
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                ans++;
                v.push_back(p);
                v[v.size()-1].push(s[x]);
            }
            flag = 0;
        }
        cout << "Case " << t++ << ": " << ans << endl;
    }
}
