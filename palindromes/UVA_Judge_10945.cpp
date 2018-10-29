#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	
	while(getline(cin, a)){
		if(a == "DONE") return 0;
		string aux; 
		for(int x = 0; x < a.length(); x++){
			if(a[x] != '.' && a[x] != '?' && a[x] != ',' && a[x] != '!' && a[x] != ' '){
				if(a[x] >= 65 && a[x] <= 90) aux += a[x] + 32;
				else aux += a[x];
			}
		}
		int p = aux.length() - 1;
		bool pal = 1;
		//cout << aux << endl;
		for(int x = 0; x < aux.length(); x++){
			if(aux[x] != aux[p]) pal = 0;
			p--;
		}
		if(pal) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
}
