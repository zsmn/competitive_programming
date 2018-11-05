#include<bits/stdc++.h>
using namespace std;

int main(){
	map<string, string> mp;
	mp["HELLO"] = "ENGLISH";
	mp["HOLA"] = "SPANISH";
	mp["HALLO"] = "GERMAN";
	mp["BONJOUR"] = "FRENCH";
	mp["CIAO"] = "ITALIAN";
	mp["ZDRAVSTVUJTE"] = "RUSSIAN";
	
	string str;
	int n = 1;
	while(cin >> str){
		if(str == "#") return 0;
		cout << "Case " << n << ": ";
		if(str == "HELLO" || str == "HOLA" || str == "HALLO" ||
		str == "BONJOUR" || str == "CIAO" || str == "ZDRAVSTVUJTE"){
			cout << mp[str];
		}else{
			cout << "UNKNOWN";
		}
		cout << endl;
		n++;
	}
}
