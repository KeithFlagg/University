//COSC 350
//Keith Flagg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void emptySet(char *s){
 int i = 0;

 while(s[i] != '\0'){

   s[i] = 0;
   i++;
 }

}

char* getname(char *dir){

 int i = 0, j = 0;

 char *filename = malloc(PATH_MAX);

 while(dir[i]!='\0'){

   if(dir[i] == '/'){ 
    if(dir[i+1]=='\0'){ 
      break;
    }
    //set to 0s
     emptySet(filename); 
     j = 0; 

   } 
   else {

     filename[j] = dir[i];
     j++;

   }
   i++;
 }

 return filename;
}

int main(int argc, char **argv){

 if(argc < 3){
   printf("./MyMv (inputdir) (outputdir)");
   return 0;
 }
 
 if(access(argv[1], F_OK) == -1){
   printf("Error, could not open the input file!\n");
   return 0;
 }

 //Check if directory
 struct stat sbuf;
 stat(argv[2], &sbuf);

 if(S_ISDIR(sbuf.st_mode)){

   //create a buffer
   char b[PATH_MAX];
   char *filename = getname(argv[1]);
   sprintf(b, "%s/%s", argv[2], filename);

   link(argv[1], b);
   unlink(argv[1]);

 } 
 else {
   link(argv[1], argv[2]);
   unlink(argv[1]);

 }

 return 0;
}
