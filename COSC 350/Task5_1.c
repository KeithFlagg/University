//COSC 350
//Keith Flagg

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h>

int openUtmpFile()
{
    int fd;
    
    fd = open("/var/run/utmp", O_RDONLY);

        if(fd < 0){
            printf("utmp file cannot be opened! \n");
            exit(1);
        }

    return fd;
}

int main(int argc, char* argv[])
{
    
    setutent();
    umask(0);

    struct utmp *buffer;
    int cnt = 0;
    int fd = openUtmpFile();

    buffer = getutent();

        while(buffer != NULL)
        {
            printf("%s \n", buffer->ut_user);

            if(buffer -> ut_type == USER_PROCESS){
                cnt ++;
            }

            buffer = getutent();

        }

    printf("The number of logged in users: %d \n", cnt);

    endutent();
    close(fd);
    return 0;
}