#include<bits/stdc++.h>
using namespace std;

int main(){
	string n;
	while(cin >> n){
		if(n == "0") break;
		while(1){
			int calc = 0;
			for(int x = 0; x < n.length(); x++){
				calc += n[x] - 48;
			}
			if(calc < 10){
				cout << calc << endl;
				break;
			}else{
				n = to_string(calc);
			}
		}
	}

}
