#include<bits/stdc++.h>
using namespace std;

int main(){
	int m = 0;
	string str;
	while(!cin.eof()){
		getline(cin, str);
		for(int x = 0; x < str.length(); x++){
			if(str[x] == '"'){
				if(m%2 == 0){
					cout << "``";
				}else{
					cout << "''";
				}
			}else{
				cout << str[x];
			}
		}
		cout << endl;
	}	
}
