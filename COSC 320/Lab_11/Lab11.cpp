#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include "graph.h"

using namespace std;

void runLab(char[]);

int main(int argc, char* argv[]){
  //if arguments are less than 1
if(!(argc > 1)){
  cout << "You must enter a file!" << endl;
  exit(1);
}
else if(argc > 1){
  int x = argc -1;
  for(int i = 0; i < x; i++){
    runLab(argv[i+1]);
  }
}
  return 0;
}

void runLab(char file[]){
  cout << "Testing " << file << "..." <<endl;
  ifstream infile;
  infile.open(file);

  if(!infile){
    cout << "Cannot open file!" << endl;
    exit(1);
  }

  char dir;
  int x = 0;
  int y = 0;
  infile >> dir;

  Graph A(true);

  while(infile >> x >> y){
    A.addEdge(x,y);
  }

  infile.close();
  if(dir == 'Y'){
    A.direction(true);
  }
  else{
    A.direction(false);
  }
  //displays graph
  A.print();
  //depth first
  A.DFS();
  //topological
  A.topSort();
  //strongly connected graph component
  A.SCGC();
}
