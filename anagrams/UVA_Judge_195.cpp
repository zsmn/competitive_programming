#include<bits/stdc++.h>
using namespace std;

bool comparator(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}

int main(){
	int n;
	string e;
	cin >> n;
	while(n--){
		cin >> e;
		sort(e.begin(), e.end(), comparator);
		do{
			cout << e << endl;
		}while(next_permutation(e.begin(), e.end(), comparator));
	}
}
