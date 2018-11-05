#include<bits/stdc++.h>
using namespace std;

int main(){
	int marcados[10000] = {0};
	int qt_it[10000] = {0};
	queue<int> q;
	vector<int> v;
	int n_cases = 1;
	
	int init, end, bottons;
	while(cin >> init >> end >> bottons){
		if(init == 0 && end == 0 & bottons == 0){
			break;
		}
		
		/* zerando */
		while(!q.empty()) q.pop();
		v.clear();
		memset(marcados, 0, sizeof(marcados));
		memset(qt_it, 0, sizeof(qt_it));
		/* zerando */
		
		for(int x = 0; x < bottons; x++){
			int aux; cin >> aux;
			v.push_back(aux);
		}
		
		int at;
		/* inserindo o valor inicial */
		q.push(init);
		marcados[init] = 1;
		qt_it[init] = 0;
		/* inserindo o valor inicial */
		
		while(!q.empty()){
			int exit = 0;
			at = q.front();
			for(int x = 0; x < bottons; x++){
				if(marcados[(at+v[x])%10000] == 0){
					marcados[(at+v[x])%10000] = 1;
					q.push((at+v[x])%10000);
					qt_it[(at+v[x])%10000] = qt_it[at] + 1;
				}
				if((at+v[x])%10000== (end)){
					cout << "Case " << n_cases << ": " << qt_it[(at+v[x])%10000] << endl;
					exit = 1;
					break;
				}
			}
			if(exit) break;
			q.pop();
		}
		if(q.empty()){
			cout << "Case " << n_cases << ": Permanently Locked" << endl;
		}
		n_cases++;
	}
}
