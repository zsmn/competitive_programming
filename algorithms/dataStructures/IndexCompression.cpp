#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;

template < typename E> class Compress {
    vector<E> vec;
    public:
    Compress() {}
    Compress(vector<E> nvec) {
        this->vec = nvec;
        build();
    }
    void insert(E element) {
        vec.push_back(element);
    }
    void build() {
        sort(vec.begin(), vec.end());
        auto pos = unique(vec.begin(), vec.end());
        vec.erase(pos, vec.end());
    }
    int operator[](E element) {
        int pos = lower_bound(vec.begin(), vec.end(), element) - vec.begin();
        if(vec[pos] != element || pos >=vec.size()) return -1;
        return pos;
    }
    int size() {
        return vec.size();
    }
};
int main () {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    Compress<int> position(vec);
    for(int i = 0; i < n; i++) {
        int pos = position[vec[i]];
        cout << pos << " ";
    }
    cout << endl;
}
