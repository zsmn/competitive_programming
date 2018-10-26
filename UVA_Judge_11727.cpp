#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	vector<int> a;
	cin >> n;
	for(int x = 0; x < n; x++){
		int p, q, r;
		cin >> p >> q >> r;
		a.push_back(p);
		a.push_back(q);
		a.push_back(r);
		sort(a.begin(), a.end());
		cout << "Case " << x + 1 << ": " << a[1] << endl;
		a.clear();
	}
}
