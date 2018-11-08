#include<bits/stdc++.h>
using namespace std;

typedef struct{
	int deonde, praonde, custo;
} aresta;

int parent[100009];
aresta ar[1000009];

int find(int x){
	if(parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

int Union(int x, int y){
	int xset = find(x);
	int yset = find(y);
	
	if(xset != yset){
		parent[xset] = yset;
		return 1;
	}
	return 0;
}

bool comp(aresta a, aresta b){
	return a.custo < b.custo;
}

int main(){
	int n, aa = 1;
	cin >> n;
	while(n--){
		memset(parent, -1, sizeof(parent));
		int qtar, ver, custo, qtAv = 0, custoTotal = 0;
		scanf("%d %d %d", &ver, &qtar, &custo);
		for(int x = 1; x <= ver; x++){
			parent[x] = x;
		}
		for(int x = 0; x < qtar; x++){
			scanf("%d %d %d", &ar[x].deonde, &ar[x].praonde, &ar[x].custo);
		}
		sort(ar, ar + qtar, comp);
		for(int x = 0; x < qtar; x++){
			if(Union(ar[x].deonde, ar[x].praonde)){
				if(ar[x].custo >= custo){
					qtAv++;
					custoTotal += custo;
				}else{
					custoTotal += ar[x].custo;
				}
			}
		}
		for(int x = 1; x <= ver; x++){
			if(parent[x] == x){
				qtAv++;
				custoTotal += custo;
			}
		}
		printf("Case #%d: %d %d\n", aa++, custoTotal, qtAv);
	}
}
