#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <list>
#include <map>

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
};

class Graph{
    private:
      map<int, vector<int>> vertices;
      list<int> node;

    public:
      Graph();
      ~Graph();

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
