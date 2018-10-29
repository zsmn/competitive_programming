#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	string aux;
	
	string s1="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string s2="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	map<char, char> m;
	
	for(int x = 0; x < s1.length(); x++) m[s1[x]] = s2[x];
	
	while(cin >> a){
		int p = a.length()-1;
		int pal = 1;
		int mirrored = 1;
		
		for(int x = 0; x < a.length(); x++){
			if(a[x] != a[p]) pal = 0;
			if(a[p] != m[a[x]]) mirrored = 0;
			p--;
		}
		
		if(pal && mirrored) cout << a << " -- is a mirrored palindrome." << endl << endl;
		else if(pal && !mirrored) cout << a << " -- is a regular palindrome." << endl << endl;
		else if(!pal && mirrored) cout << a << " -- is a mirrored string." << endl << endl;
		else cout << a << " -- is not a palindrome." << endl << endl;
	}
}
