//COSC 350
//Keith Flagg

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int nread;
  char buf;
  
  while ((nread = read(0, &buf, 1) > 0)){
    write (1, &buf, nread);
  }

  return 0;

}
