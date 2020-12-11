#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>


using namespace std;

const std::string cyan("\033[0;36m");
const std::string reset("\033[0m");
const std::string magenta("\033[0;35m");
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");

Matrix :: Matrix(){
  row = 1;
  col = 1;

  //allocates matrix space
  allMat();

  //fill with 0
  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        mat[i][j] = 0;
      }
  }

}

Matrix :: Matrix(long unsigned x, long unsigned y){
  row = x;
  col = y;

  //allocates matrix space
  allMat();

  //fill with 0
  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        mat[i][j] = 0;
      }
  }

}

Matrix :: ~Matrix(){

 for(long unsigned i = 0; i < row; i++)
  	{
  		delete [] mat[i];
  	}

  	delete [] mat;
}

void Matrix :: allMat(){
  mat = new int *[row];

  for (long unsigned i = 0; i < row; i++){
    mat[i] = new int [col];
  }
}


void Matrix :: printMatrix(){
  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        if (mat[i][j] != 0){
        cout<< cyan << setw(10) << mat[i][j] << " " << reset;
      }
      //zero
        else{
        cout<< red << setw(10) <<mat[i][j]<< " " << reset;
        }

      }
    cout << endl<<endl;
  }
cout << endl<<endl<<endl;
}

void Matrix :: fillmat(){

  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        this->mat[i][j] = (rand()%(100));
      }
  }
}

void Matrix :: makeDiag(){
  if (col != row){
    cerr<<"Matrix cannot be made diagonal!"<<endl;
    return;
  }

  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        if(i==j){
          this->mat[i][j] = (rand()%(1000));
        }
      }
  }
}

void Matrix :: makeTri(){
  if (col != row){
    cerr<<"Matrix cannot be made Triangular!"<<endl;
    return;
  }

  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        if(i<=j){
          this->mat[i][j] = (1+rand()%(1000));
        }
      }
  }
}

void Matrix :: makeId(){
  if (col != row){
    cerr<<"Matrix cannot be an Identity!"<<endl;
    return;
  }

  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        if(i==j){
          this->mat[i][j] = 1;
        }
      }
  }
}

Matrix& Matrix :: operator=(const Matrix& mx){
  if ((row != mx.row)&&(col != mx.col)){
    cerr<<"Matrices are not compatible!"<<endl;
    return *this;
  }

  else{

  for (long unsigned i = 0; i < row; i++){
          for (long unsigned j = 0; j < col; j++){
              mat[i][j] = mx.mat[i][j];
          }
      }
      return *this;
    }
}

Matrix Matrix :: operator+(const Matrix& mx){
  Matrix newMat(mx.row, mx.col);

  if ((row != mx.row)||(col != mx.col)){
    cerr<<"Matrices are not compatible!"<<endl;
  }

  else{

    for (long unsigned i = 0; i < mx.row; i++){
                for (long unsigned j = 0; j < mx.col; j++){
                    newMat.mat[i][j] = mx.mat[i][j] + mat[i][j];
                }
            }
}
return newMat;
}

Matrix Matrix :: operator-(const Matrix& mx){
  Matrix newMat(mx.row, mx.col);

  if ((row != mx.row)||(col != mx.col)){
    cerr<<"Matrices are not compatible!"<<endl;
  }

  else{

    for (long unsigned i = 0; i < mx.row; i++){
                for (long unsigned j = 0; j < mx.col; j++){
                    newMat.mat[i][j] = mx.mat[i][j] - mat[i][j];
                }
            }
}
return newMat;
}

Matrix Matrix :: operator*(const Matrix& mx){
Matrix newMat(row, mx.col);

if ((row != mx.col)){
  cerr<<"Matrices are not compatible!"<<endl;
}

for(long unsigned i = 0; i < row; i++){
  for(long unsigned j = 0; j < mx.col; j++){
      for(long unsigned k = 0; k < mx.row; k++){
        newMat.mat[i][j] += (mat[i][k] * mx.mat[k][j]);
        }
      }
}
return newMat;
}

Matrix Matrix :: operator*(int scalar){
  Matrix newMat(row, col);

  for (long unsigned i = 0; i < row; i++){
    for (long unsigned j = 0; j < col; j++){
      newMat.mat[i][j] = mat[i][j] * scalar;
    }
  }
  return newMat;
}
