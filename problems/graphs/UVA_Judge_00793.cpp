#include<bits/stdc++.h>
using namespace std;

int parent[100009];
int size[100009];

int find(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]]; // path compressing method
        x = parent[x];
    }
    return x;
}

int ach(int a, int b){
	if(find(a) == find(b)) return 1;
	else return 0;
}

void Union(int x, int y){
	int xset = find(x);
	int yset = find(y);
	
	if(xset != yset){
		if(size[xset] < size[yset]){
			parent[xset] = parent[yset];
			size[yset] += size[xset];
		}else{
			parent[yset] = parent[xset];
			size[xset] += size[yset];
		}
	}
}

int main(){
	int n, qt, a, b;
	string op;
	cin >> n;
	while(n--){
		int ans1 = 0, ans2 = 0;
		scanf("\n%d\n", &qt);
		
		for(int x = 1; x <= qt; x++){
			parent[x] = x;
			size[x] = 1;
		}
		
		while(getline(cin, op)){
			if(op == "") break;
			
			string aux1, aux2;
			
			int an = 0;
			for(int x = 2; x < op.length(); x++){
				if(op[x] != ' '){
					if(an == 0) aux1 += op[x];
					else aux2 += op[x];
				}else{
					an++;
				}
			}
			
			a = stoi(aux1);
			b = stoi(aux2);
			
			if(op[0] == 'c') Union(a, b);
			else if(op[0] == 'q'){
				if(ach(a, b)) ans1++;
				else ans2++;
			}
			
		}
		cout << ans1 << ',' << ans2 << endl;
		if(n != 0) cout << endl;
	}
}
