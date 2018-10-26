#include<bits/stdc++.h>
using namespace std;

int main(){
	queue<int> controle;
	int dep[10000];
	map<int, vector<int>> mp;
	int v, n;
	vector<int> ordem;
	
	while(cin >> v >> n){
		if(v == 0 && n == 0){
			break;
		}
		memset(dep, 0, sizeof(dep));
		mp.clear();
		while(!controle.empty()){
			controle.pop();
		}
		ordem.clear();
		for(int x = 0; x < n; x++){
			int a,b, achei = 0;
			cin >> a >> b;
			mp[a].push_back(b);
			dep[b]++;
		}
		
		for(int x = v; x >= 1; x--){
			if(dep[x] == 0){
				ordem.push_back(x);
				controle.push(x);
			}
		}
		
		while(!controle.empty()){
			int at = controle.front();
			for(int x = 0; x < (int) mp[at].size(); x++){
				dep[mp[at][x]]--;
				if(dep[mp[at][x]] == 0){
					ordem.push_back(mp[at][x]);
					controle.push(mp[at][x]);
				}
			}
			controle.pop();
		}
		
		for(int x = 0; x < (int) ordem.size(); x++){
			if(x == (int) ordem.size() - 1) cout << ordem[x];
			else cout << ordem[x] << " ";
		}
		cout << endl;
	}
}
