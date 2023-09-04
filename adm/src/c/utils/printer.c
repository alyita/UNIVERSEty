#include <stdio.h>



void writeHeader(){
    system("clear");
    printf("Wellcome to UNIVERSEty\n"); //:wq
    writeLine();

}



void writeCrrWWW(){

    writeLine();
    printf("(who)\tTeachers: 0\n\tStudants: 0\n");
    writeLine();
    printf("(where)\tRooms: 0\n");
    writeLine();
    printf("(when)\ttimelines: 0\n");
    writeLine();

    printf("\nState: [processing inputs]\n\n");
}

void writeFooter(char *msg){

    if(msg != NULL){
        printf("\n%s\n", msg);

    }

    writeLine();


}

void writeLine(){
    printf("----------------------\n");
}



void sayHello(){
    printf(" hello ");
}

