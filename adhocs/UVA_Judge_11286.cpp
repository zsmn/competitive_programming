#include<bits/stdc++.h>
using namespace std;

int main(){
	map<vector<int>, int> v;
	int n, aux, ans = 0, dabest = 0;
	vector<int> m;

	while(cin >> n){
		if(n == 0){
			break;
		}
		for(int x = 0; x < n; x++){
			for(int y = 0; y < 5; y++){
				int aux;
				cin >> aux;
				m.push_back(aux);
			}
			sort(m.begin(), m.end());
			v[m]++;
			m.clear();
		}
		
		for(auto& x: v){
			if(x.second > dabest){
				ans = x.second;
				dabest = x.second;
			}else if(x.second == dabest){
				ans += x.second;
			}
		}

		cout << ans << endl;
		v.clear();
		m.clear();
		dabest = 0;
		ans = 0;
	}
}
