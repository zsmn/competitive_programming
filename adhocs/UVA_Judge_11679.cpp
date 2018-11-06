#include<bits/stdc++.h>
using namespace std;

int main(){
	int bank[21];
	int n, m;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		memset(bank, 0, sizeof(bank));
		for(int x = 0; x < n; x++){
			cin >> bank[x];
		}
		bool can = true;
		for(int x = 0; x < m; x++){
			int devedor, credor, qt;
			cin >> devedor >> credor >> qt;
			bank[devedor-1] -= qt;
			bank[credor-1] += qt;
		}
		for(int x = 0; x < n; x++){
			if(bank[x] < 0) can = false;
		}
		if(can) cout << "S" << endl;
		else cout << "N" << endl;
	}
}
