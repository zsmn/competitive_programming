#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h>
 
typedef struct merg{
    int* vetor;
    int inicio;
    int fim;
}merg;
 
int tre=0;
pthread_t threads[1000];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 
int main() {
    printf("main\n");
    int *string;                                                    //vetor a ser ordenado
    int tam,i;                                                      //tamanho
    printf("escreva quantos numeros vai ter o vetor\n");            
    scanf("%i",&tam);                                               
    string = malloc(tam*sizeof(int));
    printf("escreva o vetor a ser ordenado\n");
    for(i=0;i<tam;i++){                                             //ler o vetor
        scanf("%i",string[i]);
    }    
    
    merg *aa;                                                        //struct pra passar de argumento para a thread
    aa = malloc(sizeof(merg));
    aa->vetor=string;
    aa->inicio=0;
    aa->fim=tam-1;
    mergesort(aa);
 
    for(i=0;i<tam;i++){
        printf("%i,",string[i]);
    }
    printf("\n");
    return 0;
}
 
void merge(int* vetor,int inicio, int meio, int fim){
    printf("merge\n");
    int i,j,k;
    int aux1 = meio - inicio + 1;
    int aux2 =  fim - meio;
    int e[aux1];
    int d[aux2];
 
    //preencher os vetores auxiliares
    for(i=0;i<aux1;i++){
        e[i]=vetor[inicio+i];
    }
    for(i=0;i<aux2;i++){
        d[i]=vetor[meio+i+
        
    }
    //fazer a troca
    i=0;
    j=0;
    k=inicio;
    while(i<aux1 && j<aux2
        
        if(e[i]<=d[j]){
            vetor[k]=e[i];
        
            i++;
        }
        else{
            vetor[k]=d[j];
            j++;
        }
        k++;
    }
    while(i<aux1){
        vetor[k]=e[i];
        i++;
        k++;
    }
    while(j<aux2){
        vetor[k]=d[j];
        j++;
        k++;
    }
};
 
void mergesort(merg *x){
    printf("mergesort\n");
    if(x->inicio < x->fim){
        int meio= (x->inicio + x->fim)/2;
        
        merg *a;
        a = malloc(sizeof(merg));
        a->vetor=x->vetor;
        a->inicio=x->inicio;
        a->fim=meio;
        pthread_create(&threads[tre],NULL,mergesort, (void*)a);
        tre++;
        
        merg *b;
        b = malloc(sizeof(merg));
        b->vetor=x->vetor;
        b->inicio=meio+1;
        b->fim=x->fim;
        pthread_create(&threads[tre],NULL,mergesort, (void*)b);
        pthread_mutex_lock(&mutex);
        tre++;
        pthread_mutex_unlock(&mutex);
 
 
        merge(x->vetor,x->inicio,meio,x->fim);        
    }
    pthread_exit(NULL);
};
