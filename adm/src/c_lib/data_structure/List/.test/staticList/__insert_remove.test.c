#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "List.c"

char *ERROR_POINTER_INITIALIZATION(){
    char *msg = (char*) malloc(128*sizeof(char));
    strcpy(msg,"Pointer is NULL. Error in pointer initialization ");

    return msg;
}


void print_list(){


}

void print_line(){

    printf("-----------\n");
}

void print_home(List* li){

    system("clear");
    printf("List:\n");

    print_line();
    printf("MAX LEN: %d\n", MAX_LEN);
    printf("current Len: %d\n\n", li->len);
    printf("Empty?? [%s]\n", (LIST_IS_EMPTY(li))?"YES":"NO");
    printf("Full?? [%s]\n", (LIST_IS_FULL(li))?"YES":"NO");

    print_line();
    LIST_PRINT_ALL(li);
    print_line();

}
void print_menu(){

    printf("Options:\n");
    printf("(p) insert end\n");
    printf("(b) insert begin\n");
    printf("(o) insert order\n");
    printf("(d) remove last\n");
    printf("(D) remove begin\n");
    printf("(r) remove key\n");

}

int main(int argc, char *argv[]){
    List* li = LIST_NEW();


    if(li == NULL){
        printf("%s\n", ERROR_POINTER_INITIALIZATION());
        return -1;
    }
    printf("sucess in list initialization\ncurrent List:\n");

    int op;
    char c, confirm;
    do {
        print_home(li);
        print_menu();
        scanf("%c", &c);
        switch(c){
            int key;

            case 'p':
                Node *no = (Node*)malloc(sizeof(Node));
                printf("type int key:\n");
                int n;
                scanf("%d", &n);
                no->key = n;

                if(LIST_INSERT_END(li, no))
                    printf("Insertion completed!\n\n");
                else 
                    printf("Insertion Failure!\n\n");
            break;

            case 'b':
                Node *no1 = (Node*)malloc(sizeof(Node));
                printf("type int key:\n");
                scanf("%d", &key);
                no1->key = key;

                if(LIST_INSERT_BEGIN(li, no1))
                    printf("Insertion completed!\n\n");
                else 
                    printf("Insertion Failure!\n\n");
            break;

            case 'o':
                Node *no3 = (Node*)malloc(sizeof(Node));
                printf("type int key:\n");
                scanf("%d", &key);
                no3->key = key;

                if(LIST_ORDER_INSERT(li, no3))
                    printf("Insertion completed!\n\n");
                else 
                    printf("Insertion Failure!\n\n");
            break;

            case 'd':
                setbuf(stdin, NULL);
                printf("Really want delete item in end of the list?\n[y/n] ");
                scanf("%c", &confirm);

                if(confirm == 'y'){
                    if(LIST_REMOVE_END(li))
                        printf("item deleted\n");
                    else
                        printf("canot delete item\n");
                }
                getchar();

            break;

            case 'D':
                setbuf(stdin, NULL);

                printf("Really want delete item in beginning of the list?\n[y/n] ");
                scanf("%c", &confirm);

                if(confirm == 'y'){
                    if(LIST_REMOVE_BEGIN(li))
                        printf("item deleted\n");
                    else
                        printf("canot delete item\n");
                }

                getchar();
            break;

            case 'r':
                printf("insert key (or 0 to cancel)\n");
                int k;
                scanf("%d", &k);
                if(k != 0){
                    if(LIST_REMOVE(li, k))
                        printf("item deleted\n");
                    else 
                        printf("canot delete item\n");
                }

            break;

            case 'q':
                op = (int) 'q';
            break;

            default:
                printf("Invalid Option!!!!\n");
            break;

        }
        
        getchar();
    
    }while(op != (int) 'q');



    printf("\nEnd... \n");
    LIST_FREE(li);
    return 0;
}
