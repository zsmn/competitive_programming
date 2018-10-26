#include<bits/stdc++.h>
using namespace std;

int subgraphs = 0;
vector<int> adjacencia[50];
int percorridos[50] = {0};

void DFS(int v){
	percorridos[v] = 1;
	for(int x = 0; x < adjacencia[v].size(); x++){
		int at = adjacencia[v][x];
		if(percorridos[at] == 0){
			percorridos[at] = 1;
			DFS(at);
		}
	}
}

int main(){
	int cases;
	string c;
	char best = '-';
	int a = 0;
	int cont = 0;
	
	cin >> cases;
	getline(cin, c);
	
	while(!cin.eof()){
		getline(cin, c);
		if(c == ""){
			a = 1;
			cont++;
			if(cont == cases + 2) return 0;
			if(best != '-'){
				int can = 1;
				for(int x = 1; x <= best-64; x++){
					if(percorridos[x] == 1){
						continue;
					}else{
						subgraphs++;
						DFS(x);
					}
				}
				cout << subgraphs << endl;
				if(cont != cases + 1) cout << endl;
				subgraphs = 0;
				for(int x = 0; x < 50; x++) adjacencia[x].clear();
				for(int x = 0; x < 50; x++) percorridos[x] = 0;
			}
			continue;
		}
		if(a == 1){
			best = c[0];
			a = 0;
		}else{
			char a1, a2;
			a1 = c[0]; // primeiro vertice
			a2 = c[1]; // segundo vertice
			adjacencia[a1-64].push_back(a2-64);
			adjacencia[a2-64].push_back(a1-64);
 		}
	}
}
