#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void deli(){}

ull calc(ull val){
    if(val == 1)return 0;
    if(val % ((ull)2) == 0)return val/2;
    return calc(val/2);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<ull> nums;
        int au = n;
        while(n--){
            ull val; cin >> val;
            nums.push_back(calc(val));
        }
        ull ans = 0;
        for(ull &a : nums){
            ans = ans ^ a;
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
