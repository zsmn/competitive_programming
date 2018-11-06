#include<bits/stdc++.h>
using namespace std;

bool isConsonant(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		return false;
	}else{
		return true;
	}
}

int main(){
	map<string, string> mp;
	int irreg, i;
	cin >> irreg >> i;

	for(int x = 0; x < irreg; x++){
		string a1, a2;
		cin >> a1 >> a2;
		mp[a1] = a2;
	}

	for(int x = 0; x < i; x++){
		string aux;
		cin >> aux;
		if(mp[aux] != "") cout << mp[aux] << endl;
		else{
			int size = aux.length();
			if(aux[size-1] == 'y' && isConsonant(aux[size-2])){
				aux[size-1] = 'i';
				aux += "es";
			}else if(aux[size-1] == 'o' || aux[size-1] == 's' || (aux[size-1] == 'h' && aux[size-2] == 'c') ||
				aux[size-1] == 'x' || (aux[size-1] == 'h' && aux[size-2] == 's')){
				aux += "es";
			}else{
				aux += 's';
			}
			cout << aux << endl;
		}
	}
}
