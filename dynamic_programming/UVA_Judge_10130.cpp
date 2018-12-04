#include<bits/stdc++.h>
using namespace std;
#define maxn 100009
/* desgraça de backtracking lixo
int knapSack(int W, int wt[], int val[], int n){
   if (n == 0 || W == 0) return 0; // caso base (primeira coluna e primeira linha zeradas)
   if (wt[n-1] > W) return knapSack(W, wt, val, n-1); // se o peso do ultimo valor n pode ser
   													 // armazenado, tenta com n-1 itens
   else return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
   //tenta preencher a matriz, valorizando o maior valor possivel, somando tambem com o da
   //linha anterior, localizado pelo peso_atual - o peso do objeto =')
} 
*/

int ks(int W, int wt[], int val[], int n){
	int K[n+1][W+1];
	
	for(int x = 0; x <= n; x++){
		for(int y = 0; y <= W; y++){
			if(x == 0 || y == 0) K[x][y] = 0; // caso base (primeira coluna e primeira linha zeradas)
			else if(wt[x-1] <= y) K[x][y] = max(val[x-1] + K[x-1][y-wt[x-1]], K[x-1][y]);   //tenta preencher a matriz, valorizando o maior valor possivel, somando tambem com o da linha anterior, localizado pelo peso_atual - o peso do objeto =') 
			else K[x][y] = K[x-1][y];
			
		}
	}
	return K[n][W];
}

int main(){
	int qt, n, tot;
	
	cin >> qt;
	while(qt--){
		tot = 0;
		int wt[maxn] = {0};
		int val[maxn] = {0};
		int qt_p; cin >> qt_p;
		for(int x = 0; x < qt_p; x++){
			cin >> val[x] >> wt[x]; 
		}
		int qt_f, aux; cin >> qt_f;
		for(int x = 0; x < qt_f; x++){
			cin >> aux;
			tot += ks(aux, wt, val, qt_p);
		}
		cout << tot << endl;
	}
}
