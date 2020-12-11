#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ofstream output;
  output.open("numbs.txt");
  int i;
  for(i = 1; i <= 100; i++){
    output << i << "\n";
  }
  return 0; 
}