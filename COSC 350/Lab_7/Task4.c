//Keith Flagg
//COSC 350

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void handler(int sig){
  if(sig==SIGUSR1)
    printf("Hi Honey! Anything wrong?\n");
  else if(sig==SIGUSR2)
    printf("Do you make trouble again?\n");
}

int main(){
  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);

  pid_t child1 = fork(), child2;
  if(child1 == 0){

  }

  else {
    child2 = fork();

      if(child2 == 0){

      }
      else {
        kill(child1, SIGUSR1);
        kill(child2, SIGUSR2);
      }
  }

  wait(NULL);
  wait(NULL);

  return 0;
}
