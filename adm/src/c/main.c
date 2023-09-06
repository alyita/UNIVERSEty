#include <stdio.h>
#include <stdio.h>
#include "lib/printer.c"

#define STATE int
#define STABLE 1
#define UNSTABLE 0

int main(){
    STATE state = UNSTABLE;

    writeHeader();

    writeCrrWWWstable(state);

    writeFooter("");

    return 0;

}

