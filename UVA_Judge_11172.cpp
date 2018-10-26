#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a, b;
	int n;
	cin >> n;
	for(int x = 0; x < n; x++){
		cin >> a >> b;
		if(a > b){
			cout << ">" << endl;
		}else if(a == b){
			cout << "=" << endl;
		}else{
			cout << "<" << endl;
		}
	}
}
