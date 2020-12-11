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

Graph :: Graph(bool di){
  time = 0;
  dir = di;
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

void Graph :: direction(bool x){
  dir = x;
}

bool Graph :: DAG(){
  if((dir == true)&&(cyclic == false)){
    return true;
  }
  else{
    return false;
  }
}

void Graph :: DFS(){
  cout << "DFS: " << endl;
  map<int, data> nodes;

  for(auto i = node.begin(); i != node.end(); i++){
    nodes[*i] = data {WHITE, -999, -1};
  }

  time = 0;

  while(DF_Stack.empty() != true){
    DF_Stack.pop();
  }

  for(auto i = node.begin(); i != node.end(); i++){
    if(nodes[*i].color == WHITE){
      DfsVisit(*i, nodes);
    }
    else if(nodes[*i].color == GRAY){
      cyclic = true;
    }
  }
  cout << endl;
}

void Graph :: DfsVisit(int n, map<int, data> &nodes){
  time++;
  nodes[n].color = GRAY;
  nodes[n].d = time;

  cout<< n <<", ";

  for(auto i = vertices[n].begin(); i != vertices[n].end(); i++){
    if(nodes[*i].color == WHITE){
      nodes[*i].prev = n;
      DfsVisit(*i, nodes);
    }
    else if(nodes[*i].color == GRAY){
      cyclic = true;
    }
  }
  time++;
  nodes[n].color = BLACK;
  nodes[n].stop = time;
  DF_Stack.push(n);
}

void Graph :: topSort(){
  if(DAG() == true){
    cout << "Topological sort: " << endl;
    stack<int> newDFS = DF_Stack;
    while(1){
      if(newDFS.empty()){
        break;
      }
      else{
        cout << newDFS.top() << "-> ";
        newDFS.pop();
      }
    }
    cout<<endl;
  }
  else{
    cerr << "Cannot perform topological sort! Graph is not a DAG!" << endl;
  }
}

void Graph :: reverse(){
for(auto i = backwards.begin(); i != backwards.end(); i++){
  int v = i->first;
  for(int v1 : i->second){
    auto temp = backwards.find(v);

    if(temp == backwards.end()){
      backwards[v] = vector<int>();
      temp = backwards.find(v1);

      if(temp == backwards.end()){
        backwards[v1] = vector<int>();
      }

      if(!dir){
        backwards[v].push_back(v1);
      backwards[v1].push_back(v);
      }

    }
  }
}
}

void Graph :: SccVisit(int n, map <int, data> &nodes){
  time++;
  nodes[n].color = GRAY;
  nodes[n].d = time;
  cout << n << ", ";

  for(auto i = vertices[n].begin(); i != vertices[n].end(); i++){
    if(nodes[*i].color == WHITE){
      nodes[*i].prev = n;
      DfsVisit(*i, nodes);
    }
    else if(nodes[*i].color == GRAY){
      cyclic = true;
    }
  }
  time++;
  nodes[n].color = BLACK;
  nodes[n].stop = time;
}

void Graph :: SCGC(){
  cout << "SCG component: " <<endl;
  reverse();
  time = 0;
  map<int, data> nodes;
  for(auto i = node.begin(); i != node.end(); i++){
    nodes[*i] = data{WHITE, -999, -1};
  }

  while(!DF_Stack.empty()){
      if(nodes[DF_Stack.top()].color == WHITE){
        SccVisit(DF_Stack.top(), nodes);
      }
      else if(nodes[DF_Stack.top()].color == GRAY){
        cyclic = true;
      }
      DF_Stack.pop();
  }
  cout << endl;
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

void Graph :: vertexCover(){
  map<int,vector<int>> newVert = vertices;
  vector<int> n;
  map<int,string> cover;

  //all vertices uncovered
    for(auto i = newVert.begin(); i != newVert.end(); i++){
      cover.insert(pair<int, string>(i->first, "Not Covered"));
    }

    for(auto i = newVert.begin(); i != newVert.end(); i++){
      if(cover[i->first] == "Not Covered"){
        for(auto j = i->second.begin(); j != i->second.end(); j++){
          if(cover[*j] == "Not Covered"){
            n.push_back(*j);
            cover[*j] = "Covered";
          }
        }
      }
    }


    cout<<"Vertex Cover: "<<endl;
    for(auto i = n.begin(); i != n.end(); i++){
      cout << *i << " ";
    }
    cout << endl;
}

void Graph :: randVertexCover(){
  map<int, vector<int>> newVert = vertices;
  vector<int> n;
  map<int, string> cover;

  for(auto i = newVert.begin(); i != newVert.end(); i++){
    cover.insert(pair<int, string>(i->first, "Not Covered"));
  }

  vector<int> rand;

  for(auto i = newVert.begin(); i != newVert.end(); i++){
    rand.push_back(i->first);
  }

random_shuffle(rand.begin(), rand.end());

  for(auto i = newVert.begin(); i != newVert.end(); i++){
    if(cover[i->first] == "Not Covered"){
      for(auto j = i->second.begin(); j != i->second.end(); j++){
        if(cover[*j] == "Not Covered"){
          n.push_back(*j);
          cover[*j] = "Covered";
        }
      }
    }
  }

cout<<"Random Vertex Cover: "<<endl;
  for(auto i = n.begin(); i != n.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
}
