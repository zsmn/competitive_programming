#include <bits/stdc++.h> 
using namespace std;

void kmpSearch(string &pattern, string &text, int *vet){
    int pattern_size = pattern.size();
    int text_size = text.size();

    int i = 0, j = 0;

    while(i < text_size){ // analisando a string
        if(text[i] == pattern[j]){ // deu bom, avança
            i++;
            j++;
        }
        if(j == pattern_size){ // se chegou no tamanho do padrao, achou
            printf("Found pattern at index %d\n", i - j);
            j = vet[j - 1];
        }
        else if(i < text_size && text[i] != pattern[j]){ // caso n
            if(j != 0){ // se ja tiver andado em j (alguma ocorrencia)
                j = vet[j - 1]; // pula pra o proximo semelhante
            }else{
                i = i + 1; // analisa o proximo caractere da str
            }
        }
    }
}

void kmpPreprocess(string &pattern, int *vet){
    int lenght = 0; // tamanho do maior prefixo sufixo
    vet[0] = 0;
    
    int i = 1;
    int sz = pattern.size();
    while(i < sz){
        if(pattern[i] == pattern[lenght]){
            lenght++;
            vet[i] = lenght;
            i++;
        }else{
            if(lenght != 0){
                lenght = vet[lenght - 1];
            }else{
                vet[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    string text = "acabacaninhaakdjfa";
    string pattern = "aninha";
    int vet[pattern.size()];

    kmpPreprocess(pattern, vet);
    kmpSearch(pattern, text, vet);
}