#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Node.c"

struct list{
    int len;
    Node *data[MAX_LEN];
};



List* LIST_NEW(){
    List *li;
    li = (List*)malloc(sizeof(List));
    if(li != NULL)
        li->len = 0;
    return li;
}

void LIST_FREE(List *li){
    free(li);
}

int LIST_LEN(List *li){
    if(li == NULL)
        return -1;
    else 
        return li->len;
}

boolean LIST_IS_FULL(List *li){
    if(li == NULL)
        return -1;

    return (li->len == MAX_LEN);
}

boolean LIST_IS_EMPTY(List *li){
    if(li == NULL)
        return -1;

    return (li->len == 0);
}

int LIST_INSERT_END(List *li, Node *no){
    if(li == NULL) return 0;
    if(LIST_IS_FULL(li)) return 0;

    li->data[li->len] = no;
    li->len++;
    return 1;
}

int LIST_INSERT_BEGIN(List *li, Node *no){
    if(li == NULL) return 0;
    if(LIST_IS_FULL(li)) return 0;

    int i;
    for(i=li->len-1; i >= 0; i--)
        li->data[i+1] = li->data[i];
    li->data[0] = no;
    li->len++;

    return 1;
}


int LIST_ORDER_INSERT(List *li, Node *no){
    if(li == NULL) return 0;
    if(LIST_IS_FULL(li)) return 0;

    int i = 0, k;
    while(i < li->len && li->data[i]->key < no->key)
        i++;

    for(k=li->len-1; k >= i; k--)
        li->data[k+1] = li->data[k];

    li->data[i] = no;
    li->len++;

    return 1;
}


int LIST_REMOVE_END(List *li){
    if(li == NULL) return 0;
    if(li->len == 0) return 0;

    li->len--;
    return 1;
}

int LIST_REMOVE_BEGIN(List *li){
    if(li == NULL) return 0;
    if(li->len == 0) return 0;

    int i;
    for(i=0; i < li->len-1; i++)
        li->data[i] = li->data[i+1];

    li->len--;
    return 1;
}


int LIST_REMOVE(List *li, int key){
    if(li == NULL) return 0;
    if(li->len == 0) return 0;

    int k, i = 0;
    while(i < li->len && li->data[i]->key != key) i++;

    if(i == li->len) return 0;

    for(k=i; k < li->len-1; k++)
        li->data[k] = li->data[k+1];

    li->len--;
    return 1;
}



int LIST_REMOVE_INDEX(List *li, int i){
    if(li == NULL) return 0;
    if(li->len == 0) return 0;

    int k;
    for(k = i; k < li->len-1; k++)
        li->data[k] = li->data[k+1];

    li->len--;
    return 1;
}

void LIST_PRINT_ALL(List *li){
    printf("[");
        int i=0, n=LIST_LEN(li);
        for(; i < n; i++){
            printf( "%d\t", NODE_GET_DATA( LIST_GET(li, i)) );
        }
    printf("]\n");
}

Node *LIST_GET(List *li, int i){
    return li->data[i];
}
