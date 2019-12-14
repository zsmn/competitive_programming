#include<bits/stdc++.h>
using namespace std;

int main(){
	int n_cases;
	vector<int> p;
	int n;
	
	cin >> n_cases;
	for(int x = 0; x < n_cases; x++){
		cin >> n;
		for(int y = 0; y < n; y++){
			int aux; cin >> aux;
			p.push_back(aux);
		}
		sort(p.begin(), p.end());
		int calc = 2 * (p[n-1] - p[0]);
		cout << calc << endl;
		p.clear();
	}
}
