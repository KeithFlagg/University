#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <stack>

using namespace std;

enum color_t{
WHITE,GRAY,BLACK
};

struct data{
  //color of node
  color_t color;
  //distance
  int d;
  //parent
  int prev;
  //time to stop
  int stop;
};

class Graph{
    private:
      int time;
      bool cyclic = false;
      bool dir;
      stack<int> DF_Stack;
      map<int, vector<int>> vertices;
      map<int, vector<int>> backwards;
      list<int> node;

    public:
      Graph();
      //directed constructor
      Graph(bool);
      ~Graph();
      //if dag return true
      bool DAG();
      //Depth first search
      void DFS();
      //strongly connected graph
      void SCGC();
      //SCC visit
      void SccVisit(int, map<int,data>&);
      //DFS visit
      void DfsVisit(int, map<int,data>&);
      //topological sort
      void topSort();
      //reverses graph
      void reverse();
      //sets direction
      void direction(bool);
      //no duplicates allowed, then adds a vertex to the graph
      void addVertex(int);
      //no self edges, then adds an edge to graph
      void addEdge(int, int);
      //prints the adjacency list of each vertex
      void print();
      //prints graph in breadth first search
      void printBFS(int);
};
#endif
