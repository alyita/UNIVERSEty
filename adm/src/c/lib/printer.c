#include <stdio.h>


void writeLine(){
    printf("-----------------------|\n");
}


void writeHeader(){
    system("clear");
    printf("Wellcome to UNIVERSEty |\n"); //:wq
    writeLine();

}



void writeCrrWWWstable(int isStable){

    writeLine();
    printf("Universetys: 1\n");
    writeLine();

    writeLine();
    printf("Teachers: 0\nStudants: 0\n");
    writeLine();
    printf("Rooms: 0\n");
    writeLine();
    printf("timelines: 0\n");
    writeLine();

    printf("\nState: ");

    if(isStable)
        printf("[STABLE]\n");
    else 
        printf("[UNSTABLE]\n");
}

void writeFooter(char *msg){

    if(msg != NULL){
        printf("\n%s\n", msg);

    }

    writeLine();


}



void sayHello(){
    printf(" hello ");
}






