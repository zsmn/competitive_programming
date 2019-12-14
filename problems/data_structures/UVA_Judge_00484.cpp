#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	map<int, int> mp;
	int n;
	while(cin >> n){
		if(!mp[n]) v.push_back(n);
		mp[n]++;
	}
	for(auto i : v){
		cout << i << " " << mp[i] << endl;
	}
}
