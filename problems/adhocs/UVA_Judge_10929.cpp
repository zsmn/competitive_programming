#include <bits/stdc++.h>
using namespace std;
#define LL long long int

bool mod(string s, int n)
{
    LL i, sum = 0;

    for(i = 0; i < s.size(); i++){
        sum = sum * 10 + (s[i]-'0');
        sum %= n;
    }

    if(sum == 0)
        return 1;
    else
        return 0;
}

int main()
{
    string a;

    while(cin >> a){
        if(a == "0")
            break;

        if(mod(a, 11))
            cout << a << " is a multiple of 11." << endl;
        else
            cout << a << " is not a multiple of 11." << endl;
    }
    return 0;
}