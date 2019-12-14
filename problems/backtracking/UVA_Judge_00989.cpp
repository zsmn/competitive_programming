#include<bits/stdc++.h>
using namespace std;

int N = 1;

bool acharVazias(int mat[][9], int &linha, int &coluna);
bool ehValido(int mat[][9], int inicioLinha, int inicioColuna, int num);

bool resolverSudoku(int mat[][9]){
	int linha, coluna;
	
	if(!acharVazias(mat, linha, coluna)) return true; //solucionado
	
	for(int x = 1; x <= N; x++){
		if(ehValido(mat, linha, coluna, x)){
			mat[linha][coluna] = x;
			
			if(resolverSudoku(mat)) return true;
			
			mat[linha][coluna] = 0; // deu merda boy
		}
	}
	return false;
}

bool acharVazias(int mat[][9], int &linha, int &coluna){
	for(linha = 0; linha < N; linha++){
		for(coluna = 0; coluna < N; coluna++){
			if(mat[linha][coluna] == 0){
				return true;
			}
		} 
	}
	return false;
}

bool procurarLinha(int mat[][9], int linha, int num){
	for(int x = 0; x < N; x++){
		if(mat[linha][x] == num){
			return true;
		}
	}
	return false;
}

bool procurarColuna(int mat[][9], int coluna, int num){
	for(int x = 0; x < N; x++){
		if(mat[x][coluna] == num){
			return true;
		}
	}
	return false;
}

bool verificarBloco(int mat[][9], int linha, int coluna, int num){
	int calc = sqrt(N);
	for(int x = 0; x < calc; x++){
		for(int y = 0; y < calc; y++){
			if(mat[linha + x][coluna + y] == num){
				return true;
			}
		}
	}
	return false;
}

bool ehValido(int mat[][9], int linha, int coluna, int num){
	int calc = sqrt(N);
	return !procurarLinha(mat, linha, num) &&
		   !procurarColuna(mat, coluna, num) &&
		   !verificarBloco(mat, linha - linha%calc, coluna - coluna%calc, num);
}


void printarSudoku(int mat[][9]){
	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			if(y == N - 1) cout << mat[x][y];
			else cout << mat[x][y] << " ";
		}
		cout << endl;
	}
}

int main(){
	int casos = 0;

	while(cin >> N){
		casos++;
		if(casos > 1) cout << endl;
		N = N * N;
		int mat[N][9];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> mat[i][j];
			}
		}
		if(resolverSudoku(mat) == true) printarSudoku(mat);
		else cout << "NO SOLUTION" << endl;
	}

}
