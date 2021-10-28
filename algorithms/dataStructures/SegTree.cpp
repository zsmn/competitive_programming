#include<iostream>
using namespace std;

//programed for somatory of range
template<class T = int> class Segtree{
    //depends on problem
    static const int _segmaxn = 1e5;
    T segt[_segmaxn*4];
    T arr[_segmaxn];
    int n;

    public:
    Segtree(int _n): n(_n) {};
    Segtree(int _n, T arr[]): n(_n) {
        build(arr);
    }

    void build(T arr[]) {
        for(int i = 0; i < n; i++)
            this->arr[i] = arr[i];
        build(1, 0, n-1);
    }
    //return type depends on the problem
    long long query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, T x) {
        return update(1, 0, n-1, pos, x);
    }

    private:
    void build(int index, int tl, int tr) {
        int left = index << 1;
        int right = (index << 1) + 1;
        int mid = (tl + tr) >> 1;

        if(tl == tr) {
            segt[index] = arr[tl];
        } else {
            build(left, tl, mid);
            build(right, mid + 1, tr);
            //depends on problem
            segt[index] = segt[left] + segt[right]; 
        }
    }
    //return type depends on the problem   
    long long query(int index, int tl, int tr, int l, int r) {
        int left = index << 1;
        int right = (index << 1) + 1;
        int mid = (tl + tr) >> 1;

        if(tl > r || tr < l) {
            //depends on the problem
            return 0; 
        } else if(tl >= l && tr <= r) {
            return segt[index];
        } else {
            auto q1 = query(left, tl, mid, l, r);
            auto q2 = query(right, mid + 1, tr, l, r);
            //depends on the problem
            return q1 + q2;
        }
    }

    void update(int index, int tl, int tr, int pos, int x) {
        int left = index << 1;
        int right = (index << 1) + 1;
        int mid = (tl + tr) >> 1;

        if(pos < tl || pos > tr) return;
        if(tl == tr) {
            segt[index] = x;
        } else {
            update(left, tl, mid, pos, x);
            update(right, mid + 1, tr, pos, x);
            //depends on the problem
            segt[index] = segt[left] + segt[right];
        }
    }
};

int main() {
    int n;
    int vet[1000];
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> vet[i];
        cout << vet[i] << " ";
    } cout << endl;

    Segtree<int> seg(n, vet);

    int q;
    cin >> q;

    while(q--) {
        int op, arg1, arg2;
        cin >> op >> arg1 >> arg2;
        if(op == 0) {
            cout << seg.query(arg1, arg2) << endl;
        } else {
            seg.update(arg1, arg2);
        }
    }

}