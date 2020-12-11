//Keith Flagg
//COSC 350

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig){
 if(sig==SIGQUIT)
   printf("SIGQUIT was entered during the loop\n");
 else if(sig==SIGINT)
   printf("SIGINT was entered during the loop\n");
}

int main(){

 sigset_t new_set, old_set;
 //Clear signals
 sigemptyset(&new_set); 
 //adds the signals to the set
 sigaddset(&new_set, SIGINT);
 sigaddset(&new_set, SIGQUIT);
 
 sigprocmask(SIG_BLOCK, &new_set, &old_set);

 int i=0;
 //Block SIGINT and SIGQUIT
 for(i=0; i<5; i++){
   printf("First loop(SIGINT & SIGQUIT are blocked): %d\n", i);
   sleep(1);
 }

 printf("Unblocking SIGQUIT\n");
 //send signals to the handler
 signal(SIGINT, handler);
 signal(SIGQUIT, handler);
 //Reset the mask
 sigprocmask(SIG_SETMASK, &old_set, NULL);
 //use only SIGINT
 sigdelset(&new_set, SIGQUIT);
 sigprocmask(SIG_BLOCK, &new_set, NULL);
 //Reset the handler
 signal(SIGINT, SIG_DFL);
 signal(SIGQUIT, SIG_DFL);
 /* Second loop, SIGINT is blocked */
 for(i=0; i<5; i++){
   printf("Second loop(SIGINT is blocked): %d\n", i);
   sleep(1);
 }
}