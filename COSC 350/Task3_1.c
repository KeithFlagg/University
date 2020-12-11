//COSC 350
//Keith Flagg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


// Concatenates strings into the output 
unsigned int appendStr(const char *str, const char *str1, char *output){
  int size=0;
  int i=0;

    while(str[i]!='\0'){
      output[size]=str[i];
      size++;
      i++;
    }

  i=0;
    
    while(str1[i]!='\0'){
      output[size]=str1[i];
      i++;
      size++;
    }

  output[size]='\0';

  return size;
}

//length of the string in bytes.
unsigned int strleng(const char *s){
  int i = 0;
  while(s[i]!='\0')
    i++;
  return i;
}

void zerostr(char *str){
  int i=0;

  while(str[i]!='\0'){
    str[i]=0;
    i++;
  }
}

int main(){

  umask(0);
  
  char home[] = "/home/keith/";
  int home_size = strleng(home);
  
  printf("Home Dir: %s\n", home);

  //create the dirs.
  char buffer[256];

  int dsize = appendStr(home, "Dir1", buffer);
  //Create dir

  int rval = mkdir(buffer,0777);
  zerostr(buffer);

  //Create another dir
  dsize = appendStr(home, "Dir2", buffer);

  //Create another directory.
  rval = mkdir(buffer,0777);

  //Create a third dir.
  dsize = appendStr(buffer,"/Dir12/", buffer);
  rval = mkdir(buffer,0777);

  // Open the filedes
  int ifd = open("/home/keith/COSC350/hello", O_RDONLY);
  if(ifd == -1){
    printf("error occured while opening the input file hello.\n");
    return -1;
  }

  zerostr(buffer);
  appendStr(home, "Dir2/Dir12/hello", buffer);

  //Create output file as executable, read, write for all.
  int ofd = open(buffer, O_CREAT | O_WRONLY, 0777);
  if(ofd==-1){
    printf("error occured while opening the output file hello.\n");
    close(ifd);
    return -1;
  }

  zerostr(buffer);

  char buff[1];
  int n_read;

  //Copy the file contents.
  while ((n_read = read(ifd, buff, 1) > 0)){
    //writes to clone file
    write(ofd, buff, n_read);
  }

  close(ifd);
  close(ofd);

  zerostr(buffer);

  //Create symbolic links.
  appendStr(home, "Dir2/Dir12/",buffer);
  symlink(buffer, "toDir12");

  zerostr(buffer);
  appendStr(home, "Dir2/Dir12/hello", buffer);
  symlink(buffer, "toHello");
  
  return 0;
}
