#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Bit {
    typedef long long ll;
    vector<ll> bit;
    ll size;
    public:
    Bit(vector<ll> vec){
        build(vec);
    }
    void build(vector<ll> vec) {
        size = vec.size(); // seting the size of bit
        bit.assign(size, 0);
        for(ll i = 0; i < size; i++) bit[i] = vec[i]; //copying the content of vec
        for (int i = 1; i < size; i++) {
			int p = i + (i & -i); // index to parent range
			if (p < size) {
				bit[p] += bit[i];
			}
		}
    }

    ll query(ll i) {
        ll range_sum = 0;
        while(i > 0) {
            range_sum += bit[i];
            i -= i & -i;
        }
        return range_sum;
    }

    void update(ll  i, ll d) {
        while(i < size) {
            bit[i] += d;
            i += i & (-i);
        }
    }
};

int main() {
    vector<ll> vec;
    ll n;
    cin >> n;
    vec.resize(n + 1);
    for(ll i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    ll q;
    cin >> q;
    Bit bit(vec);
    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout << bit.query(r) - bit.query(l-1) << endl;
    }
}
