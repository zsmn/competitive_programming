#include <stdio.h>

int HoarePartition(int A[], int l, int r){
    int pivo, i, j, aux;
    pivo = A[l];
    i = l;
    j = r+1;
    do{
       do{
        i++;
       }while(A[i] < pivo && i < r);
       do{
        j--;
       }while(A[j] > pivo);
       aux = A[i];
       A[i] = A[j];
       A[j] = aux;
    }while(i < j);
    aux = A[i];
    A[i] = A[j];
    A[j] = aux;
    aux = A[l];
    A[l] = A[j];
    A[j] = aux;
    return j;
}

void Quicksort(int A[], int l, int r){
    int S;
    if(r > l){
        S = HoarePartition(A, l, r);
        Quicksort(A, l, S-1);
        Quicksort(A, S+1, r);
    }
}


int main(){
    int tam;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);
    int Array[tam];
    printf("Digite os numeros do array: ");
    for(int j = 0; j < tam; j++){
        scanf("%d", &Array[j]);
    }
    Quicksort(Array, 0, tam-1);
    printf("Array ordenado: ");
    for(int m = 0; m < tam; m++){
        printf("%d", Array[m]);
        printf(" ");
    }
    printf("\n");    
}
