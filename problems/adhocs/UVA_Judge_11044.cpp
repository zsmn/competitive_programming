#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int x = 0; x < n; x++){
		int a, b;
		cin >> a >> b;
		a = a / 3;
		b = b / 3;
		
		cout << a * b << endl;
	}
}
