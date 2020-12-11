//COSC 350
//Keith Flagg

#include <stdio.h>
#include <stdlib.h>

char* mygetenv(char* name)
{
    extern char**  environ;
    int i, j, val;

    for(i = 0; i < 71; i++)
    {
        val = 1;

        for(j = 0; j < 3; j++)
        {
            if(environ[i][j] != name[j])
            {
                val = 0;
            }
        }
        if(val == 1)
        {
            return environ[i];
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc!=2){
        printf("Please use the following syntax: ./myenv [env_variable_name]\n");
        return -1;
    }

    //tests the function
    printf("mygetenv(%s)...\n", argv[1]);

    char *env = mygetenv(argv[1]);

    if(env != NULL){
        printf("mygetenv: %s\n", env);

    } else {
        printf("mygetenv NULL\n");
    }

    env = getenv(argv[1]);
    if(env != NULL){

        printf("getenv: %s\n", env);
    } else {

        printf("getenv NULL\n");
    }
    return 0;
}