//COSC 350
//Keith Flagg
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void appendReverse(int filedes[], int offset[], int curr, int file, int buffersize){

  char buffer[buffersize];
  //read the last byte
  int i = 0, total = offset[curr];
  while (i <= total){

    //lseek rev
    pread(filedes[curr], buffer, buffersize, (total - i));

    //writes to clone
    write(filedes[file], buffer, buffersize);
    i++;
  }

}

int main(){

  //copy byte by byte
  int buffersize = 1; 

  //opens foo
  int filedes[2], offset[2]; 

  if((filedes[0] = open("foo", O_RDONLY)) < 0){
    printf("Creat File Open Error On foo");
  }

  //opens foo12
  umask(0);
  //rwxrw----
  filedes[1] = open("foorev", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP);

  //use lseek to go to the end
  if((offset[0] = lseek (filedes[0], O_RDONLY, SEEK_END)) == -1){
    printf("lseek Error");
  }

  //append foo and foo1 to foo12 in reverse
  appendReverse(filedes, offset, 0, 1, buffersize);

  close(filedes[0]);
  close(filedes[1]);
  close(filedes[2]);
 
  return 0;

}