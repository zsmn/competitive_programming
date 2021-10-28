#include <iostream>
#include <algorithm>
using namespace std;

void remove_leading_zero(string& s) {
    long long leading_zero = 0;
    for(auto c : s) {
        if(c != '0') break;
        leading_zero++;
    }
    if(leading_zero == s.size()) {
        s = "0";
    } else {
        s.erase(s.begin(), s.begin() + leading_zero);
    }
}
string treat(string& str) {
    remove_leading_zero(str);
    string signal = "";
    if(str[0] == '-') {
        signal = "-";
        str.erase(0, 1);
    } else if(str[0] == '+') {
        str.erase(0, 1);
    }
    remove_leading_zero(str);
    if(str == "0") return str;
    str = signal + str;
    return str;
}
bool bigger(string &s1, string &s2) {
    if(s1.size() != s2.size()) 
        return s1.size() > s2.size();
    return s1 > s2;
}
string sum(string& s1, string &s2) {
    string a = treat(s1);
    string b = treat(s2);
    long long len = max(a.size(), b.size());

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    string ans = "";
    for(long long i = 0; i < len; i++) {
        int v1 = (i < a.size()) ? a[i] - '0': 0;
        int v2 = (i < b.size()) ? b[i] - '0': 0;
        int result = v1 + v2 + carry;
        carry = 0;
        if(result >= 10) {
            result -= 10;
            carry = 1;
        }
        ans += (char)(result + '0');
    }
    if(carry) ans += (char)(carry + '0');
    reverse(ans.begin(), ans.end());
    ans = treat(ans);
    return ans;
}
string sub(string &s1, string &s2) {
    string a = treat(s1);
    string b = treat(s2);
    if(bigger(b, a)) a.swap(b);

    long long len = max(a.size(), b.size());

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    string ans = "";
    for(long long i = 0; i < len; i++) {
        int v1 = (i < a.size()) ? a[i] - '0': 0;
        int v2 = (i < b.size()) ? b[i] - '0': 0;
        int result = v1 - v2 - carry;
        carry = 0;
        if(result < 0) {
            result += 10;
            carry = 1;
        }
        ans += (char)(result + '0');
    }
    reverse(ans.begin(), ans.end());
    ans = treat(ans);
    return ans;
}

int main() {
    string s1, s2, s;
    cin >> s1 >> s2;
    s = sum(s1, s2);
    s = sum(s, s);
    s = sub(s, s1);
    s = sub(s, s2);
    cout << s << endl;
    
}

