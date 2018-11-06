#include<bits/stdc++.h>
using namespace std;

int superdigit(long long n){
	int calc = 0;
	while(n != 0){
		calc += n % 10;
		n = n / 10;
	}
	if(calc < 10) return calc;
	else superdigit(calc);
}

int main(){
	long long n;
	while(cin >> n){
		if(n == 0) break;
		cout << superdigit(n) << endl;
	}
}
