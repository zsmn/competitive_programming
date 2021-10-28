#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		vector<int> v(4);
		for(int j = 0; j < 4; j++)
			cin >> v[j];
		sort(v.begin(), v.end());

		if(v[0] == v[3])
			cout << "square" << endl;
		else if(v[0] == v[1] && v[2] == v[3])
			cout << "rectangle" << endl;
		else if(v[0] + v[1] + v[2] > v[3])
			cout << "quadrangle" << endl;
		else
			cout << "banana" << endl;
	}

	return 0;
}