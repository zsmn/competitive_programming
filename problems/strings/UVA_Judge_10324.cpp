#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n_case = 0;
	int n;
	
	while(cin >> s){
		int at = 0;		
		cin >> n;
		for(int x = 0; x < n; x++){
			int a, b;
			cin >> a >> b;
			if(!at){
				at = 1;
				cout << "Case " << ++n_case << ":" << endl;
			}
			int from = min(a, b);
			int to = max(a, b);
			int start = s[from];
			int flag = 0;
			for(int y = from; y <= to; y++){
				if(s[y] != start) flag = 1; 
			}
			if(flag) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		
	}
}
