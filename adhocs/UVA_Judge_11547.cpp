#include<bits/stdc++.h>
using namespace std;

long long int ans;

int main(){
	int n;
	cin >> n;
	while(n--){
		cin >> ans;
		ans *= 567;
		ans /= 9;
		ans += 7492;
		ans *= 235;
		ans /= 47;
		ans -= 498;
		ans /= 10;
		cout << abs(ans%10) << endl;
	}
}
