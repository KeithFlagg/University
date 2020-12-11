//COSC 350
//Keith Flagg

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void appendfile(int filedes[], int curr, int file, int buffersize){

  char buffer[buffersize];
  while (read(filedes[curr], buffer, buffersize) > 0){
    //writes to clone
    write(filedes[file], buffer, buffersize);
  }

}


int main(){

  //copies file byte by byte
  int buffersize = 1; 

  //opens foo and foo1
  int filedes[3], offset;

  if((filedes[0] = open("foo", O_RDONLY)) < 0){
    printf("File Error (foo)");
  }

  if((filedes[1] = open("foo1", O_RDONLY)) < 0){
    printf("File Error (foo1)");
  }

  //open foo12
  umask(0);
  filedes[2] = open("foo12", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP);

  //use lseek to go to the end of the file
  if((offset = lseek (filedes[2], O_WRONLY | O_APPEND, SEEK_END)) == -1){
    printf("lseek Error!");
  }

  //appends foo and foo1 to foo12
  appendfile(filedes, 0, 2, buffersize);
  appendfile(filedes, 1, 2, buffersize);

  close(filedes[0]);
  close(filedes[1]);
  close(filedes[2]);

  return 0;

}
