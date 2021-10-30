//Algoritmo de Busca Linear

#include <bits/stdc++.h>

using namespace std;

int linearSearch(int x, int tam, int* v){    
    for(int i = 0 ; i < tam ; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int* vetor = new int[10];        
    int ans;
    for(int i = 0 ; i < 10 ; i++){
        vetor[i] = (i-1)*10;
    }
    ans = linearSearch(5, 10, vetor);
    
    if(ans != -1){
        printf("O valor 5 foi encontrado na posição %d pela Buscar Linear ;)\n", ans);
    }
    else{
        puts("O valor 5 não foi encontrado pela Busca Linear.. :(");
    }
    
    delete vetor;
}