#ifndef MATRIX_H
#define MATRIX_H
//macros to define header

class Matrix{
// class constructor, destructor and prototypes

private:
double **mat;
long unsigned row;
long unsigned col;

long unsigned count = 0;

public:
Matrix();
//overloaded constructor
Matrix(long unsigned x, long unsigned y);
//copy constructor
Matrix(const Matrix&);
//destructor
~Matrix();

//prints
void printMatrix();
//allocates
void allMat();
//fills matrix with zeros
void fillZero();
//makes random Matrix
void fillmat();
//makes a diagonal matrix
void makeDiag();
//makes a triangle Matrix
void makeTri();
//makes an identity Matrix
void makeId();
//finds transpose of a matrix
Matrix transpose();
//calculates the inverse of a Matrix
Matrix inverse();
//adds padding to the Matrix
Matrix addPadding(long unsigned, long unsigned);
//checks if matrix is symmetrical
bool symm();
//checks if matrix is a power of 2
bool isPowOfTwo(long unsigned);
//assigns a number to matrix i,j
void setNum(long unsigned i, long unsigned j, double n){mat[i][j] = n;};
//returns matrix num
double getNum(long unsigned i, long unsigned j){return mat[i][j];}
//returns counter of arithmetic operations
long unsigned getCount(){return count;}




long unsigned getRow() const {return row;}

long unsigned getCol() const {return col;}

//assigns entire matrices
Matrix& operator=(const Matrix& mx);
//multiplies matrices
Matrix operator*(const Matrix& mx);
//Scalar multiplication bonus
Matrix operator*(int scalar);
//adds matrices
Matrix operator+(const Matrix& mx);
//subtracts matrices
Matrix operator-(const Matrix& mx);

};
#endif
