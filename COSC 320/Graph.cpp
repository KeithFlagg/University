#include "graph.h"

//fancy colors
const std::string cyan("\033[0;36m");
const std::string reset("\033[0m");
const std::string magenta("\033[0;35m");
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");

Graph :: Graph(){
//default
}

Graph :: ~Graph(){
//default
}

void Graph :: addEdge(int a, int b){
  addVertex(a);
  addVertex(b);

  if(a == b){
    cout << red << "cannot make a self edge!" << reset <<endl;
    return;
  }

    vertices[a].push_back(b);
    vertices[b].push_back(a);
}

void Graph :: addVertex(int a){
  auto v = vertices.find(a);
  if(v == vertices.end()){
    vertices[a] = vector<int>();
    node.push_back(a);
  }
}

void Graph :: print(){

  for(auto i = vertices.begin(); i != vertices.end(); i++){
    cout << "Node: " << i->first << " ";
    cout << "Neighbors: ";
    for(int j : i->second){
      cout << green << j << reset << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void Graph :: printBFS(int s){
  cout << "Printing from vertice: " << s << "!"<<endl;

  map<int, data> curr;
  for(auto i = node.begin(); i != node.end(); i++){
    curr[*i] = data{WHITE, -999, -1};
  }

  curr[s].color = GRAY;
  curr[s].d = 0;
  queue<int> q;
  q.push(s);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto i = vertices[u].begin(); i != vertices[u].end(); i++){
      if(curr[*i].color == WHITE){
				curr[*i].color = GRAY;
				curr[*i].d = curr[u].d + 1;
				curr[*i].prev = u;
				q.push(*i);
				cout << red << *i << reset << ", ";
			}
    }
    curr[u].color = BLACK;
  }
  cout << endl;
}
