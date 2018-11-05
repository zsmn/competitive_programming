#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	int qt = 0;

	while(cin >> n >> m){
		map<int, int> vec1;
		map<int, int> vec2;
		qt = 0;

		if(n == 0 && m == 0){
			break;
		}
		for(int x = 0; x < n; x++){
			int aux;
			cin >> aux;
			vec1[aux]++;
		}
		for(int x = 0; x < m; x++){
			int aux;
			cin >> aux;
			vec2[aux]++;
			if(vec1[aux] >= 1 && vec2[aux] >= 1){
				qt++;
			}
		}
		cout << qt << endl;
		vec1.clear();
		vec2.clear();
	}
}
