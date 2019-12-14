#include<bits/stdc++.h>
using namespace std;

int main(){
	string res;
	string ans;
	while(getline(cin, res)){
		ans = "";
		int cont[300] = {0}, better = 0;
		for(int x = 0; x < res.length(); x++){
			if(res[x] >= 65 && res[x] <= 122) cont[res[x]] += 1;
			if(cont[res[x]] > better) better = cont[res[x]];
		}
		for(int x = 65; x <= 122; x++){
			if(cont[x] == better) ans += (char) x;
		}
		sort(ans.begin(), ans.end());
		cout << ans << " " << better << endl;
	}
}
