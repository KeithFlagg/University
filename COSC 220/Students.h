#ifndef STUDENTS_H
#define STUDENTS_H

// definition of STUDENTS_H
struct Students{
      char lastName[20]; //students last name
      char firstName[20]; //students last lastName
      int idNumber; //student ID
      Students(); //constructor
      void printStudent(); //print student info
  };
  #endif
