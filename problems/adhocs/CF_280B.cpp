#include<bits/stdc++.h>
using namespace std;
 
int main(){
	vector<int> pos;
	int n, l;
	cin >> n >> l;
	
	for(int x = 0; x < n; x++){
		int aux;
		cin >> aux;
		pos.push_back(aux);	
	}
	sort(pos.begin(), pos.end());
	double ans = 0;
	for(int x = 0; x < n - 1; x++){
		if(abs(pos[x] - pos[x+1])/2.0 > ans){
			ans = abs(pos[x] - pos[x+1])/2.0;
		}
	}
	if(pos[0] > ans){
		ans = pos[0];
	}
	if(abs(pos[n-1]-l) > ans){
		ans = abs(pos[n-1]-l);
	}
	
	cout.precision(10);
	cout << fixed << ans << endl;
}
