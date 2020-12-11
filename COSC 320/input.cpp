//Keith Flagg
//COSC 320
//Dr. Anderson

#include <iostream>
#include "matrix.h"
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <fstream>
//#include "matrix.cpp"

using namespace std;

const std::string green("\033[1;32m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

//calculates products
Matrix res(Matrix&, Matrix&);

int main(int argc, char **argv){
  //seed for rand
  srand(time(0));
  ifstream inFile;
  string* industries = new string[30];
  string name;
  double num = 0;
  long unsigned indcount = 0;

  inFile.open(argv[1]);

  while(!inFile.eof()){
    //gets names
    for (long unsigned i = 0; inFile.peek() != '-'; i++){
      getline(inFile, industries[i]);
      indcount++;
    }

    Matrix nums(indcount, indcount);
    //gets matrix vals

      for(long unsigned i = 0; i < indcount; i++){
        for(long unsigned j = 0; j < indcount; j++){
          inFile >> num;
          nums.setNum(i,j,num);
        }

      Matrix demand(indcount, 1);

      for(long unsigned i = 0; i < indcount; i++){
        inFile >> num;
        demand.setNum(i, 0, num);
      }

      Matrix Product = res(nums, demand);
      cout<<"---------------------------------"<<endl;
      cout<<green<<"Amount of each product needed is: "<<endl;
      for(long unsigned i = 0; i < indcount; i++){
        cout<<industries[i]<<": "<<Product.getNum(i,0)<<" units!"<<reset<<endl;
      }
      cout<<"---------------------------------"<<endl;
    }


  }

delete []industries;
inFile.close();
return 0;
}

Matrix res(Matrix& nums, Matrix& demand){
  Matrix id = nums;
  id.makeId();

  Matrix result = ((id - nums).inverse()) * demand;
  return result;
}
