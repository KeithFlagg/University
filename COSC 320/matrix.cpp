#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

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

Matrix::Matrix(const Matrix& mat1) {
	mat = new double*[mat1.row];

	for (long unsigned i = 0; i < mat1.row; i++) {
		mat[i] = new double[mat1.col];
	}
	row = mat1.row;
	col = mat1.col;

	for (long unsigned i = 0; i < row; i++) {
		for (long unsigned j = 0; j < col; j++) {
			mat[i][j] = mat1.mat[i][j];
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
  mat = new double *[row];

  for (long unsigned i = 0; i < row; i++){
    mat[i] = new double [col];
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
        this->mat[i][j] = (1+rand()%(10));
      }
  }
}

void Matrix :: fillZero(){

  for(long unsigned i = 0; i < row; i++){
      for(long unsigned j = 0; j < col; j++){
        this->mat[i][j] = 0;
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

//flips matrix along i=j
Matrix Matrix :: transpose(){
  Matrix trans = Matrix(row, col);

  for(long unsigned i = 0; i < row; i++){
  		for(long unsigned j = 0; j < col; j++){
  			trans.mat[j][i] = mat[i][j];
  		}
  	}
  	return trans;
}

bool Matrix :: symm(){
Matrix sym = *this;
//flips matrix along i=j
Matrix sym1 = sym.transpose();

for (long unsigned i = 0; i < row; i++){
  for(long unsigned j = 0; j < col; j++){
    if (sym.mat[i][j] != sym1.mat[i][j]){
      return false;
    }
  }
}
  return true;
}

bool Matrix :: isPowOfTwo(long unsigned n){
  if (n == 0){
    return false;
  }
  return (ceil(log2(n)) == floor(log2(n)));
}

Matrix Matrix :: addPadding(long unsigned rows, long unsigned cols){
  long unsigned len = 1;

  //next power of two assigned to the new rows
  while(len < rows){
    len *= 2;
  }

Matrix newMat(len,len);
newMat.makeId();

  for(long unsigned i = 0; i < newMat.row; i++){
    for(long unsigned j = 0; j < newMat.col; j++){
      if ((i < rows) && (j < cols)){
        newMat.mat[i][j] = mat[i][j];
      }
    }
  }
  return newMat;
}


Matrix Matrix :: inverse(){
  count=0;

  if (col != row){
    cerr<<"Not a square matrix! (NxN)"<<endl<<endl;
    return *this;
  }

if ((row == 1)&&(col == 1)){
  Matrix newMat(col, row);
  if(mat[0][0] != 0){
    newMat.mat[0][0] = ((1.0)/(mat[0][0]));
    count++;
  }
  else{
    newMat.mat[0][0] = 0;
    count++;
  }
  return newMat;
}
//cout<<"Cheking if pow of two (true 1, 0 false)."<<endl;
//cout<<isPowOfTwo(row)<<endl;
//keeps track of the row val before the check

long unsigned oldRow = row;
if (!isPowOfTwo(row)){
  //adds padding to make the matrix a power of two
  Matrix newMat = addPadding(row, col);
  count++;
  Matrix temp = newMat.inverse();
  count++;
  Matrix temp2(oldRow, oldRow);

  count++;
  for(long unsigned i = 0; i < oldRow; i++){
    for(long unsigned j = 0; j < oldRow; j++){
      count++;
      temp2.mat[i][j] = temp.mat[i][j];
    }
  }
return temp2;
}

//if matrix is not symmetrical (A^−1 = (A^T*A)^−1 * A^T)
//cout<<"Testing if matrix is symmetrical (1 true, 0 false)."<<endl;
//cout<<symm()<<endl;

if (!symm()){
  Matrix tmp = *this;
  count++;
  //A^T
	Matrix trans = tmp.transpose();
  count++;
  //A^T * A
	Matrix tmp1 = trans * tmp;
  count++;
  Matrix tmpinv = tmp1.inverse();
  count++;
  //(A^T*A)^-1 * A^T
	Matrix tmp2 = tmpinv * trans;
  count++;

    return tmp2;
}


//1.
//splits up the matrix
Matrix B(row/2, col/2);
Matrix CT(row/2, col/2);
Matrix C(row/2, col/2);
Matrix D(row/2, col/2);

for (long unsigned i = 0; i < row; i++) {
		for (long unsigned j = 0; j < col; j++) {

			if ((i < (row/2)) && (j < (col/2))) {
        count++;
				B.mat[i][j] = mat[i][j];
			}
			if ((i < (row/2)) && (j >= (col/2))) {
        count++;
				CT.mat[i][j - (col/2)] = mat[i][j];
			}
			if ((i >= (row/2)) && (j < (col/2))) {
        count++;
				C.mat[i - (row/2)][j] = mat[i][j];
			}
			if ((i >= (row/2)) && (j >= (col/2))) {
        count++;
				D.mat[i - (row/2)][j - (col/2)] = mat[i][j];
			}
		}
	}

//2.
Matrix Bin = B.inverse();
count++;
//3.
Matrix W = C * Bin;
count++;
Matrix Wtrans = Bin * CT;
count++;
//4.
Matrix X = W * CT;
count++;
//5.
Matrix S = (D - X);
count++;
//6.
Matrix V = S.inverse();
count++;
//7.
Matrix Y = V * W;
count++;
Matrix Ytrans = Y.transpose();
count++;
//8.
Matrix T = (Ytrans * -1);
count++;
Matrix U = (Y * -1);
count++;
//9.
Matrix Z = Y * Wtrans;
count++;
Matrix R = Bin + Z;
count++;

Matrix newMat(row, col);

//10.
//combines smaller matrices by sectors
for (long unsigned i = 0; i < row; i++) {
  for (long unsigned j = 0; j < col; j++) {
    if ((i < (row/2)) && (j < (col/2))) {
      count++;
      newMat.mat[i][j] = R.mat[i][j];
    }
    if ((i < (row/2)) && (j >= (col/2))) {
      count++;
      newMat.mat[i][j] = T.mat[i][j - (col/2)];
    }
    if ((i >= (row/2)) && (j < (col/2))) {
      count++;
      newMat.mat[i][j] = U.mat[i - (row/2)][j];
    }
    if ((i >= (row/2)) && (j >= (col/2))) {
      count++;
      newMat.mat[i][j] = V.mat[i - (row/2)][j - (col/2)];
    }
  }
}

return newMat;
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
                    newMat.mat[i][j] = mat[i][j] - mx.mat[i][j];
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
