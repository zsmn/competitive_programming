//Algoritmo de Busca Ternária Iterativa

#include <bits/stdc++.h>

using namespace std;

int ternarySearch (int x, int tam, int* v) {    
    int inicio, meio1, meio2, fim;    
    inicio = 0;
    fim = tam-1;
    
    while (inicio <= fim) {        
        meio1 = inicio + (fim - inicio)/3;
        meio2 = fim - (fim - inicio)/3;
        
        if (v[meio1] == x) return meio1;
        else if (v[meio2] == x) return meio2;
        else if (x < v[meio1]) fim = meio1 - 1;
        else if (x > v[meio2]) inicio = meio2 + 1;
        else {
            inicio = meio1 + 1;
            fim = meio2 - 1;
        }
    }
    return -1;    
}

int main(){    
    int tam, x;
    tam = 15;
    int v[tam];
    srand(time(NULL));
    cout << "Vetor: ";
    for (int i = 0; i < tam; i++){
        v[i] = i;
        cout << v[i] << " ";
    }
    cout << endl;
    x = rand() % tam;
    int pos = ternarySearch(x, tam, v);
    pos != -1? cout << x << " encontrado na posição "<< pos << endl : cout << x << " não encontrado" << endl;
    return 0;
}