const int LIM = 2e5 + 10;
int sz[LIM], root[LIM];

int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b])
            root[b] = a;  
        else root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}
