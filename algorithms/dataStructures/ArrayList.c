#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    int maxSize; 
    int listSize; 
    int curr; 
    int* listArray;
}List;

List* create_list(int size){
    List* l = (List*) malloc(sizeof(List));
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = (int*) malloc(size * sizeof(int));
    return l;
}

void insert(List * l, int it){
    int i;
    if(l->listSize >= l->maxSize){
        exit(1);
    }
    i = l->listSize;
    while(i > l->curr){
        l->listArray[i] = l->listArray[i-1];
        i--;
    }
    l->listArray[l->curr] = it;
    l->listSize++;
}

void remov(List * l){
    if(l->curr < 0 || l->curr >= l->listSize){
        return;
    }
    int it = l->listArray[l->curr];
    int i = l->curr;
    while(i < l->listSize-1){
        l->listArray[i] = l->listArray[i+1];
        i++;
    }
    l->listSize--;
}

void next(List * l){
    if(l->curr < l->listSize){
        l->curr++;
    }
}

void prev(List * l){
    if(l->curr != 0){
        l->curr--;
    }
}

int count(List *l, int K){
    int i = 0;
    int j = 0;
    while(i < l->listSize){
        if(l->listArray[i] == K){
            j++;
        }
        i++;
    }
    return j;
}

int main(){
    List *list;
    int casos, ope, num;
    char acao[6];
    scanf("%d", &casos);
    for(int m = 0; m < casos; m++){
        list = create_list(100);
        scanf("%d", &ope);
        for(int n = 0; n < ope; n++){
            scanf(" %s", &acao);
            if(!strcmp(acao, "insert")){
                scanf("%d", &num);
                insert(list, num);
            }else if(!strcmp(acao, "count")){
                scanf("%d", &num);
                printf("%d\n",count(list, num));
            }else if(!strcmp(acao, "remove")){
                remov(list);
            }else if(!strcmp(acao, "next")){
                next(list);
            }else if(!strcmp(acao, "prev")){
                prev(list);
            }

        }
        free(list);
    }
}
