#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "List.c"

char *ERROR_POINTER_INITIALIZATION(){
    char *msg = (char*) malloc(128*sizeof(char));
    strcpy(msg,"Pointer is NULL. Error in pointer initialization ");

    return msg;
}


int main(int argc, char *argv[]){

    List* li = LIST_NEW();
    if(li == NULL){
        printf("%s\n", ERROR_POINTER_INITIALIZATION());
        return -1;
    }
    printf("sucess in list initialization\n");

    //code here

    LIST_FREE(li);
    printf("list clear\n");

    return 0;
}
