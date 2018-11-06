#include<bits/stdc++.h>
using namespace std;

bool isVogal(char c){
	if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
		return true;
	else
		return false;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		string a1, a2;
		cin >> a1 >> a2;
		bool eh = true;
		if(a1.length() == a2.length()){
			int p = a1.length();
			for(int x = 0; x < p; x++){
				if(!(isVogal(a1[x]) && isVogal(a2[x]) && (a1[x] != a2[x]))){
					eh = false;
				}
			}
		}else{
			eh = false;
		}
		if(eh) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
