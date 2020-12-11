#ifndef MATRIX_H
#define MATRIX_H
//macros to define header

class Matrix{
// class constructor, destructor and prototypes

private:
int **mat;
long unsigned row;
long unsigned col;


public:
Matrix();
Matrix(long unsigned x, long unsigned y);
~Matrix();

//prints
void printMatrix();
//allocates
void allMat();
//makes random Matrix
void fillmat();
//makes a diagonal matrix
void makeDiag();
//makes a triangle Matrix
void makeTri();
//makes an identity Matrix
void makeId();

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
