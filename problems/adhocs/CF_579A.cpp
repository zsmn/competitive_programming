#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int cases;
	cin >> cases;
 
	while(cases--){
		int n_students;
		cin >> n_students;
		int v[n_students];
		for(int x = 0; x < n_students; x++) cin >> v[x];
		bool can = false;
		for(int x = 0; x < n_students; x++){
			bool clockwise = true;
			bool counterclockwise = true;
			int bb = x;
			for(int y = 0; y < n_students - 1; y++){
				// checking clockwise
					if(v[bb % n_students] > v[(bb+1) % n_students]) clockwise = false;
				// checking counterclockwise
					if(v[bb % n_students] < v[(bb+1) % n_students]) counterclockwise = false;
			        bb++;
			}
			if(clockwise || counterclockwise){
			    can = true;
			    break;
			}
		}
		if(can) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
