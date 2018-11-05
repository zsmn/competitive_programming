#include<bits/stdc++.h>
using namespace std;

int main(){
	map<string, string> d;
	string str, str2, str2a;
	int ach = 1;

	while(getline(cin, str)){
		ach = 1;
		if(str == ""){
			break;
		}
		for(int x = 0; x < str.length(); x++){
			if(str[x] != ' ' && ach){
				str2 += str[x];
			}else if(str[x] == ' '){
				ach = 0;
			}else if(str[x] != ' ' && !ach){
				str2a += str[x];
			}
		}
		d[str2a] = str2;
		str2 = "";
		str2a = "";
	}

	while(getline(cin, str)){
		if(d[str] == "") cout << "eh" << endl;
		else cout << d[str] << endl;
	}

}
