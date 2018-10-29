#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, aa = 0;
	string str;
	
	cin >> n;
	getline(cin, str);
	
	while(n--){
		getline(cin, str);
		
		string straux;
		for(int x = 0; x < str.length(); x++){
			if(str[x] != '.' && str[x] != '?' && str[x] != ',' && str[x] != '!' && str[x] != ' ' && str[x] != '(' && str[x] != ')'){
				straux += str[x];
			}
		}
		
		int ans = (int) sqrt(straux.length());
		
		int qt = straux.length()-1;
		bool fodeu = 0;
		for(int x = 0; x < straux.length(); x++){
			if(straux[x] != straux[qt]) fodeu = 1;
			qt--;
		}
		
		//cout << straux << endl;
		
		if(ans * ans == straux.length() && !fodeu){
			cout << "Case #" << aa + 1 << ":" << endl << ans << endl;
		}else{
			cout << "Case #" << aa + 1 << ":" << endl << "No magic :(" << endl;
		}
		
		aa++;
	}
}
