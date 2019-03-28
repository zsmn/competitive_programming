#include<bits/stdc++.h>
using namespace std;

map<char, int> dictionary;

bool comp(char a, char b){
    bool k = dictionary[a] == dictionary[b];
    if(k){
        return a < b;
    }
	return dictionary[a] > dictionary[b];
}

int main(){
	vector<char> a;
	int n, novo;
	string s;

	cin >> n;
    	getline(cin, s);
	for(int x = 0; x < n; x++){
		getline(cin, s);
		for(int y = 0; y < s.length(); y++){
			if(s[y] != ' ' && s[y] >= 97 && s[y] <= 122){
				novo = s[y] - 32;
				if(dictionary[novo] == 0) a.push_back(novo);
				dictionary[novo]++;
			}else if(s[y] >= 65 && s[y] <= 90){
				novo = s[y];
				if(dictionary[novo] == 0) a.push_back(novo);
				dictionary[novo]++;
			}
		}
	}

	sort(a.begin(), a.end(), comp);

	for(int x = 0; x < a.size(); x++){
		cout << a[x] << " " << dictionary[a[x]] << endl;
	}

}
