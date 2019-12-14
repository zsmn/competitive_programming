#include<bits/stdc++.h>
using namespace std;

bool used[50];
bool isprime[50];
int p[20];

void solve(int p[20], int at, int n){

	if(at == n){
		if(isprime[p[at-1] + p[0]]){
			for(int x = 0; x < n; x++){
				if(x != n - 1) cout << p[x] << " ";
				else cout << p[x];
			}
			cout << endl;
		}
	}

	for(int x = 2; x <= n; x++){
		if(used[x]) continue;
		
		if(isprime[p[at-1] + x]){
			p[at] = x;
			used[x] = true;
			solve(p, at + 1, n);
			
			used[x] = false;
		}
	}
}

int main(){
	int n, n_casos = 0;
	isprime[2] = 1;
	isprime[3] = 1;
	isprime[5] = 1;
	isprime[7] = 1;
	isprime[11] = 1;
	isprime[13] = 1;
	isprime[17] = 1;
	isprime[19] = 1;
	isprime[23] = 1;
	isprime[29] = 1;
	isprime[31] = 1;
	isprime[37] = 1;
	
	while(cin >> n){
		memset(p, -1, sizeof(p));
		memset(used, 0, sizeof(used));
		p[0] = 1;
		if(n_casos != 0) cout << endl;
		cout << "Case " << ++n_casos << ":" << endl;
		solve(p, 1, n);
	}
	
}
