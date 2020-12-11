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

using namespace std;
//fancy colors
const std::string green("\033[1;32m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

int main(){

cout<<fixed<<setprecision(6);

//seed for rand
srand(time(0));
long unsigned col,row,col1,row1,col2,row2,col3,row3;
col = 2;
row = 2;
col1 = 3;
row1 = 3;
col2 = 20;
row2 = 20;
col3 = 25;
row3 = 25;
Matrix M1(row,col);
Matrix M2(row, col);
Matrix ident(row,col);

cout<<"inverting a 2x2 matrix:"<<endl;
M1.fillmat();
cout<<"Matrix 1:"<<endl;
M1.printMatrix();

M2 = M1.inverse();
cout<<"Matrix 2: "<<endl;
M2.printMatrix();

cout<<"Multiplying inverse by original (identity): "<<endl;
ident = M2*M1;

ident.printMatrix();

cout<<"multiplying 2x2 matricies (M1 * M2):"<<endl;

M2 = M1*M2;

M2.printMatrix();

cout<<"Subtracting 2x2 matricies (M1 - M2):"<<endl;

M1 = M1 - M2;

M1.printMatrix();

cout << "Adding 2x2 matrices (M1 + M2):"<<endl;

M2 = M1 + M2;

M2.printMatrix();

cout << "Transposing M1:"<<endl;
cout<<"Before:"<<endl;
M1.printMatrix();
M2 = M1.transpose();
cout<<"After:"<<endl;
M2.printMatrix();



cout<<"Padding a non power of two matrix: (M4)"<<endl;
cout<<"Needs padding:"<<endl;
Matrix M3(col1,row1);
M3.fillmat();
M3.printMatrix();
Matrix M4 = M3.addPadding(row1,col1);
cout<<"Done:"<<endl;
M4.printMatrix();

cout<<"Testing symm()..."<<endl;


if (M4.symm()){
  cout<<"The matrix is symmetrical! (M4)"<<endl;
}
else{
  cout<<"The matrix is not symmetrical! (M4)"<<endl;
}

cout<<"inverting 20 x 20 matrix!"<<endl;
Matrix M5(col2, row2);

M5.fillmat();

Matrix M6 = M5.inverse();
cout<<M5.getCount()<<" operations while inverting!"<<endl<<endl;

cout<<"inverting 25 x 25 matrix!"<<endl;
Matrix M7(col3,row3);
M7.fillmat();

Matrix M8 = M7.inverse();
cout<<M7.getCount()<<" operations while inverting!"<<endl;

return 0;
}
