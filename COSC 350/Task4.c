//Keith Flagg
//COSC 350

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;
    int size = 0;
    char *cmd;

    // count arguments
    for(i = 1; i < argc; i++) {
        size += strlen(argv[i]);
    }

    //must use calloc for array
    cmd = calloc(size, sizeof(char));

    for(i = 1; i < argc; i++){
        sprintf(cmd, "%s %s", cmd, argv[i]);
    }

    char buf[BUFSIZ];
    FILE *ptr;
   	
    //reads command using popen
    if ((ptr = popen(cmd, "r")) != NULL){

        while (fgets(buf, BUFSIZ, ptr) != NULL){
            (void) printf("%s", buf);
        }

    }

    pclose(ptr);

    return 0;
}