#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include "graph.h"

using namespace std;

int main(){
  Graph G1;
  Graph G2;

cout << "Inserting vertices into the first graph..." << endl;
G1.addEdge(1,4);
cout << "1 -> 4"<< endl;
G1.addEdge(8,4);
cout << "8 -> 4"<< endl;
G1.addEdge(4,3);
cout << "4 -> 3"<< endl;
G1.addEdge(3,6);
cout << "3 -> 6"<< endl;
G1.addEdge(6,4);
cout << "6 -> 4"<< endl;
G1.addEdge(1,7);
cout << "1 -> 7"<< endl;

cout << "Graph 1: " << endl;
G1.print();
G1.printBFS(1);

cout << "Inserting vertices into the second graph..." << endl;
G2.addEdge(1,4);
cout << "1 -> 4"<< endl;
G2.addEdge(8,4);
cout << "8 -> 4"<< endl;
G2.addEdge(4,3);
cout << "4 -> 3"<< endl;
G2.addEdge(3,6);
cout << "3 -> 6"<< endl;
G2.addEdge(6,5);
cout << "6 -> 5"<< endl;
G2.addEdge(1,4);
cout << "1 -> 4"<< endl;

cout << "Graph 2: " << endl;
G2.print();
G2.printBFS(3);

  return 0;
}
