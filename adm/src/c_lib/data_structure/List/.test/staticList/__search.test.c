#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "lib/List.c"

#define SIZE 4242


char *ERROR_POINTER_INITIALIZATION(){
    char *msg = (char*) malloc(128*sizeof(char));
    strcpy(msg,"Pointer is NULL. Error in pointer initialization ");

    return msg;
}

int *generate_vec_keys(int *len){
    int *vec = (int*)malloc(SIZE*sizeof(int));

    if (access("data", F_OK) == 0){
        printf("have a file named data. want load it?\n[y/n] ");
        setbuf(stdin, NULL);
        char confirm;
        scanf("%c", &confirm);

        if(confirm == 'y'){
            FILE *file_keys = fopen("data", "rb");
            if(file_keys == NULL){
                printf("Failed to read the file.\n");
            }

            size_t load_op = fread(vec, sizeof(int), SIZE, file_keys);
            *len = (int) load_op;
            printf("%d itens loaded!\n");
            setbuf(stdin, NULL);
            getchar();
            getchar();
            return vec;
        }
    }

    printf("rand option. (1-42000)\n");
    int i;
    srand(time(NULL));

    for(i=0; i < SIZE; i++)
        *(vec+i) = (rand() % 42000)+1;

    *len = SIZE;
    return vec;
}
void load_list_data(List *li, int *vec, int n){
    int i;
    for(i = 0; i < n; i++){
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->key = *(vec + i);
        if(LIST_ORDER_INSERT(li, newNode))
            continue;
        else {
            printf("List insertion error ar index: %d\ntry insert in end:\n", i);
            if(LIST_INSERT_END(li, newNode))
                printf("inserted in end of list!\n");
            else
                printf("node at %d not addedded\n", i);
                
        }
    }
    printf("%d itens inserted in list\n", n);
    return;
}

int main(int argc, char *argv[]){
    List* li = LIST_NEW();
    if(li == NULL){
        printf("%s\n", ERROR_POINTER_INITIALIZATION());
        return -1;
    }
    printf("sucess in list creatinon.\nInitializing data...\n");

    int n, *keys;

    keys = generate_vec_keys(&n);
    load_list_data(li, keys, n);

    printf("Current vectr:\n");
    LIST_PRINT_ALL(li);

    free(keys);
    LIST_FREE(li);
    return 0;
}
