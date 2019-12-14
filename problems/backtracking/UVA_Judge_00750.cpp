#include<bits/stdc++.h>
using namespace std;

int queen_chess[8][8];
int pos[8];
int cont = 0;
int linhasel;
int colsel;

void init(){
	cont = 0;
	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			queen_chess[x][y] = 0;
		}
	}
}

bool checar(int linha, int coluna){
	/* verifica a linha toda a esquerda */
	for(int x = 0; x < coluna; x++)
		if(queen_chess[linha][x]) return false;
	/* verifica a diagonal 'pra cima' */
	for(int x = linha, y = coluna; x >= 0 && y >= 0; x--, y--)
		if(queen_chess[x][y]) return false;
	/* verifica a diagonal 'pra baixo' */
	for(int x = linha, y = coluna; y >= 0 && x < 8; x++, y--)
		if(queen_chess[x][y]) return false;
	
	return true;
}

bool resolver(int coluna){ 
	if(coluna >= 8) return true; // se todas as rainhas estiverem posicionadas
	for(int x = 0; x < 8; x++){
		if(checar(x, coluna)){ // se for uma posição que admita uma rainha
			queen_chess[x][coluna] = 1; // seta 1 pra dizer que vai 'por uma rainha ali pra testar'
			pos[coluna] = x + 1;
			if(resolver(coluna + 1)){ // recorrencia babys
				if(queen_chess[linhasel][colsel]){
					if(cont > 8) cout << ++cont << "      ";
					else cout << " " << ++cont << "      ";
					for(int x = 0; x < 8; x++){
						if(x != 7) cout << pos[x] << " ";
						else cout << pos[x];
					}
					cout << endl;
					//return true; // so vai chegar aqui se conseguir resolver todas as posições
				}
			}

			queen_chess[x][coluna] = 0; // aqui faz o backtracking (caso deu merda, saio voltando)
		}
	}
	return false; // caso saia do laço sem dar return true, n tem como
}

int main(){
	int n, x, y;
	cin >> n;
	while(n--){
		cin >> x >> y;
		init();
		//queen_chess[x-1][y-1] = 1;
		linhasel = x - 1;
		colsel = y - 1;
		pos[y-1] = x;
		cout << "SOLN       COLUMN" << endl;
    	cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		resolver(0);
		if(n != 0) cout << endl; 
	}
}
