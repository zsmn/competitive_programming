#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link{
    int element;
    struct Link *next;
}node;

node* create_link(int it, node* nextval){
    node* n = (node*) malloc(sizeof(node));
    n->element = it;
    n->next = nextval;
    return n;
}

typedef struct List{
    node* head;
    node* tail;
    node* curr;
    int cnt;
}list;

list* create_list(){
    list* l = (list*) malloc(sizeof(list));
    l->curr = l->tail = l->head = create_link(0,NULL);
    l->cnt = 0;
    return l;
}

void insert(list* l, int it){
    l->curr->next = create_link(it, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    (l->cnt)++;
}

void prev(list* l){
    if(l->curr == l->head){
        return;
    }
    node* temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}

void next(list* l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

int remov(list* l){
    node* temp = l->curr->next;
    if(l->curr->next == NULL){
        return NULL;
    }
    int it = l->curr->next->element;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    (l->cnt)--;
    free(temp);
    return it;
}

int count(list* l, int K){
    int i = 0;
    int j = 0;
    node* temp = l->head;
    do{
        if(temp->element == K){
            i++;
        }
        temp = temp->next;
        j++;
    }while(j <= l->cnt);
    return i;
}


int main(){
    int casos, ope, num;
    char acao[6];
    list* l = NULL;
    scanf("%d", &casos);
    for(int i = 0; i < casos; i++){
        l = create_list();
        scanf("%d", &ope);
        for(int j = 0; j < ope; j++){
            scanf(" %s", &acao);
            if(!strcmp(acao, "insert")){
                scanf("%d", &num);
                insert(l, num);
            }else if(!strcmp(acao, "count")){
                scanf("%d", &num);
                printf("%d\n",count(l, num));
            }else if(!strcmp(acao, "remove")){
                remov(l);
            }else if(!strcmp(acao, "next")){
                next(l);
            }else if(!strcmp(acao, "prev")){
                prev(l);
            }
        }
        free(l);
    }
}
