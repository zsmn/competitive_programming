//espero que gostem
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define tam 110
#define inf 999999
int indice[tam], a;
typedef struct{
    int peso, second, first;
}graph;
int ds[tam];
int n, m;
int findDS(int curr){
    if(ds[curr]==-1) return curr;
    ds[curr] = findDS(ds[curr]);
    return ds[curr];
}
void unionDS(int a, int b){
    int root1 = findDS(a);
    int root2 = findDS(b);
    if(root1!=root2){
        ds[root2] = root1;
    }
}
int cmp(graph v, graph w){
    return (v.peso <w.peso);
}
void subsetFunc(int nos){
    for(int i=0; i<nos; i++){
        ds[i] = -1;
    }
}

void kruskal(vector<graph> grafo, vector<int> &indice){
subsetFunc(n);
int numMST = n;
graph temp;
int val=0, sum=0; 
//a=0;
    while(numMST>1 && val<grafo.size()){
        temp = grafo[val++];
        if(findDS(temp.first)!=findDS(temp.second)){
            unionDS(temp.first, temp.second);
            sum+=temp.peso;
            indice.push_back(val-1);
            //indice[a++] = val-1;
            numMST--;
        }
    }
    printf("%d ", sum);
}
int main(){
  return 0;
}
