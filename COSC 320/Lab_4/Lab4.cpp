//Keith Flagg
//COSC 320
//Dr. Anderson

#include <iostream>
#include "Matrix.h"
#include <chrono>
#include <ctime>
#include <stdlib.h>


using namespace std;
//fancy colors
const std::string green("\033[1;32m");
const std::string reset("\033[0m");
const std::string red("\033[0;31m");

int main(){

//seed for rand
srand(time(0));
long unsigned col,row;
col = 5;
row = 5;


Matrix M1(row,col);
Matrix M2(col,row);
Matrix MULT(M1.getRow(),M2.getCol());

cout<<endl;
cout<<"testing..."<<endl;
M1.makeTri();
cout<<"Matrix 1: "<<endl<<endl;
M1.printMatrix();

cout<<"Matrix 2: "<<endl<<endl;
M2.fillmat();
M2.printMatrix();

cout<<"Product Matrix: "<<endl<<endl;
auto start = std::chrono::system_clock::now();
MULT = M1 * M2;
auto end = std::chrono::system_clock::now();

MULT.printMatrix();

std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at: " << green<<std::ctime(&end_time)<<reset
<< "elapsed time: " << green << elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;

//second test
col = 100;
row = 100;

Matrix M3(row,col);
M3.fillmat();
Matrix M4(col,row);
M4.fillmat();
Matrix MULT1(M3.getRow(),M4.getCol());

cout<< "Multiplying full matrix of " << red << "100 X 100 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT1 = M3 * M4;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//third test
col = 100;
row = 100;

Matrix M5(row,col);
M5.makeId();
Matrix M6(col,row);
M6.makeId();
Matrix MULT2(M5.getRow(),M6.getCol());

cout<< "Multiplying identity matrix of " << red << "100 X 100 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT2 = M5 * M6;
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//fourth test
col = 100;
row = 100;

Matrix M7(row,col);
M7.makeTri();
Matrix M8(col,row);
M8.makeTri();
Matrix MULT3(M7.getRow(),M8.getCol());

cout<< "Multiplying triangular matrix of " << red << "100 X 100 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT3 = M7 * M8;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//fifth test
col = 100;
row = 100;

Matrix M9(row,col);
M9.makeDiag();
Matrix M10(col,row);
M10.makeDiag();
Matrix MULT4(M9.getRow(),M10.getCol());

cout<< "Multiplying diagonal matrix of " << red << "100 X 100 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT4 = M9 * M10;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;

//sixth test
col = 200;
row = 200;

Matrix M11(row,col);
M11.fillmat();
Matrix M12(col,row);
M12.fillmat();
Matrix MULT5(M11.getRow(),M12.getCol());

cout<< "Multiplying full matrix of " << red << "200 X 200 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT5 = M11 * M12;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//seven test
col = 200;
row = 200;

Matrix M13(row,col);
M13.makeId();
Matrix M14(col,row);
M14.makeId();
Matrix MULT6(M13.getRow(),M14.getCol());

cout<< "Multiplying identity matrix of " << red << "200 X 200 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT6 = M13 * M14;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//eight test
col = 200;
row = 200;

Matrix M15(row,col);
M15.makeTri();
Matrix M16(col,row);
M16.makeTri();
Matrix MULT7(M15.getRow(),M16.getCol());

cout<< "Multiplying triangular matrix of " << red << "200 X 200 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT7 = M15 * M16;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//ninth test
col = 200;
row = 200;

Matrix M17(row,col);
M17.makeDiag();
Matrix M18(col,row);
M18.makeDiag();
Matrix MULT8(M17.getRow(),M18.getCol());

cout<< "Multiplying diagonal matrix of " << red << "200 X 200 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT8 = M17 * M18;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//tenth test
col = 400;
row = 400;

Matrix M19(row,col);
M19.fillmat();
Matrix M20(col,row);
M20.fillmat();
Matrix MULT9(M19.getRow(),M20.getCol());

cout<< "Multiplying full matrix of " << red << "400 X 400 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT9 = M19 * M20;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//eleventh test
col = 400;
row = 400;

Matrix M21(row,col);
M21.makeId();
Matrix M22(col,row);
M22.makeId();
Matrix MULT10(M21.getRow(),M22.getCol());

cout<< "Multiplying identity matrix of " << red << "400 X 400 elements!" << reset << endl;
start = std::chrono::system_clock::now();


MULT10 = M21 * M22;

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//thwelfth test
col = 400;
row = 400;

Matrix M23(row,col);
M23.makeTri();
Matrix M24(col,row);
M24.makeTri();
Matrix MULT11(M23.getRow(),M23.getCol());

cout<< "Multiplying triangular matrix of " << red << "400 X 400 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT11 = M23 * M24;
end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//thirteenth test
col = 400;
row = 400;

Matrix M25(row,col);
M25.makeDiag();
Matrix M26(col,row);
M26.makeDiag();
Matrix MULT12(M25.getRow(),M26.getCol());

cout<< "Multiplying diagonal matrix of " << red << "400 X 400 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT12 = M25 * M26;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//fourteenth test
col = 600;
row = 600;

Matrix M27(row,col);
M27.fillmat();
Matrix M28(col,row);
M28.fillmat();
Matrix MULT13(M27.getRow(),M28.getCol());

cout<< "Multiplying full matrix of " << red << "600 X 600 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT13 = M27 * M28;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//fifteenth test
col = 600;
row = 600;

Matrix M29(row,col);
M29.makeId();
Matrix M30(col,row);
M30.makeId();
Matrix MULT14(M29.getRow(),M30.getCol());

cout<< "Multiplying identity matrix of " << red << "600 X 600 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT14 = M29 * M30;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//sixteenth test
col = 600;
row = 600;

Matrix M31(row,col);
M31.makeTri();
Matrix M32(col,row);
M32.makeTri();
Matrix MULT15(M31.getRow(),M32.getCol());

cout<< "Multiplying triangular matrix of " << red << "600 X 600 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT15 = M31 * M32;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//seventeenth test
col = 600;
row = 600;

Matrix M33(row,col);
M33.makeDiag();
Matrix M34(col,row);
M34.makeDiag();
Matrix MULT16(M33.getRow(),M34.getCol());

cout<< "Multiplying diagonal matrix of " << red << "600 X 600 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT16 = M33 * M34;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;

//eighteenth test
col = 800;
row = 800;

Matrix M35(row,col);
M35.fillmat();
Matrix M36(col,row);
M36.fillmat();
Matrix MULT17(M35.getRow(),M36.getCol());

cout<< "Multiplying full matrix of " << red << "800 X 800 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT17 = M35 * M36;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//ninteenth test
col = 800;
row = 800;

Matrix M37(row,col);
M37.makeId();
Matrix M38(col,row);
M38.makeId();
Matrix MULT18(M37.getRow(),M38.getCol());

cout<< "Multiplying identity matrix of " << red << "800 X 800 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT18 = M37 * M38;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//twentieth test
col = 800;
row = 800;

Matrix M39(row,col);
M39.makeTri();
Matrix M40(col,row);
M40.makeTri();
Matrix MULT19(M39.getRow(),M40.getCol());

cout<< "Multiplying triangular matrix of " << red << "800 X 800 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT19 = M39 * M40;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//twentyfirst test
col = 800;
row = 800;

Matrix M41(row,col);
M41.makeDiag();
Matrix M42(col,row);
M42.makeDiag();
Matrix MULT20(M41.getRow(),M42.getCol());

cout<< "Multiplying diagonal matrix of " << red << "800 X 800 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT20 = M41 * M42;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;

//twentysecond test
col = 1000;
row = 1000;

Matrix M43(row,col);
M43.fillmat();
Matrix M44(col,row);
M44.fillmat();
Matrix MULT21(M43.getRow(),M44.getCol());

cout<< "Multiplying full matrix of " << red << "1000 X 1000 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT21 = M43 * M44;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//twentythird test
col = 1000;
row = 1000;

Matrix M45(row,col);
M45.makeId();
Matrix M46(col,row);
M46.makeId();
Matrix MULT22(M45.getRow(),M46.getCol());

cout<< "Multiplying identity matrix of " << red << "1000 X 1000 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT22 = M45 * M46;

end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//twentyfourth test
col = 1000;
row = 1000;

Matrix M47(row,col);
M47.makeTri();
Matrix M48(col,row);
M48.makeTri();
Matrix MULT23(M47.getRow(),M48.getCol());

cout<< "Multiplying triangular matrix of " << red << "1000 X 1000 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT23 = M47 * M48;
end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;


//twentyfifth test
col = 1000;
row = 1000;

Matrix M49(row,col);
M49.makeDiag();
Matrix M50(col,row);
M50.makeDiag();
Matrix MULT24(M49.getRow(),M50.getCol());

cout<< "Multiplying diagonal matrix of " << red << "1000 X 1000 elements!" << reset << endl;
start = std::chrono::system_clock::now();

MULT24 = M49 * M50;
end = std::chrono::system_clock::now();

elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " << green<<ctime(&end_time)<<reset
<< "elapsed time: " << green <<elapsed_seconds.count() << "s\n"<<reset<<"-------------------------------"<<endl<<endl;




return 0;
}
