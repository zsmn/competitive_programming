#include <stdio.h>

//Parte "Merge" do algoritmo de mergesort, é copiado para um array temporário temp somente o interválo que estaremos ordenando,
void merge(int A[], int l, int r){
    int temp[r+1];
    int cur;
    for(int i = l;i <= r; i++){
        temp[i] = A[i];
    }
    int m = (l+r)/2;
    int i1 = l;
    int i2 = m+1;
    for(cur = l; cur <= r; cur++){
        if(i1 == m+1){
            A[cur] = temp[i2];
            i2++;
        }else if(i2 > r){
            A[cur] = temp[i1]; 
            i1++;
        }else if(temp[i1] <= temp[i2]){
            A[cur] = temp[i1];
            i1++;
        }else{
            A[cur] = temp[i2];
            i2++;
        }
    }
}


void mergesort(int A[], int l, int r){
    if (l < r){
        int m = (l+r)/2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);
        merge(A, l, r);
    }
}
//Função Mergesort, utilizando chamada recursiva e sempre pegando a metade do array 

int main(){
    int tam;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);
    int Array[tam];
    printf("Numeros escolhidos: \n");
    for(int j = 0; j < tam; j++){
        scanf("%d", &Array[j]);
    }
    mergesort(Array, 0, tam-1);
    printf("Array ordenado: ");
    for(int m = 0; m < tam; m++){
        printf("%d", Array[m]);
        printf(" ");
    }
    printf("\n");     
}
