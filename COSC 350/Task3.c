//Keith Flagg
//COSC 350

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){

  umask(0);
  int fd1 = open("foo", O_CREAT | O_RDWR, 0666);
  int fd2 = dup(fd1);
  pid_t pid = fork();

  if(pid == 0){
    write(fd2, "Hi, Mom", 7);
    close(fd2);
    return 0;
  }

  wait(NULL);

  lseek(fd1, SEEK_SET,0);
  //buffer for writing
  char buf[7];

  read(fd1, buf, 7);

  printf("My son said %s\n", buf);

  close(fd1);

  return 0;

}